#ifndef SRC_TYPEERASURE_BASE_SHAPE_H
#define SRC_TYPEERASURE_BASE_SHAPE_H

#include <memory>
#include <utility>

namespace typeerasure {

// Type Erasure Pattern
// External-Polymorphism Pattern を使い定義した Model (型と振る舞いの組み) を
// Pimpl (Bridge Pattern) で隠蔽することで、
// 型と振る舞いを分離しつつ、ShapeModelに型引数を渡す必要もなくなった。
// 更に 内部でclone()メソッド (Prototype Pattern) を使うことで、
// 値コピーを可能にし、値セマンティクスを実現した。

// Manual Virtual Dispatch
// Concept を継承するかわりに、呼び出すべき関数の型を自分で計算する
// 型はコンパイル時にテンプレートで決まるので、型安全。
// 関数呼び出し時のポインタ参照を、 vtable を参照する１回分減らせるため
// パフォーマンスが向上する。

// 型消去されたShapeクラス：ShapeT, DrawStrategyの型情報を持たない
class Shape {
 public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer)
      : pimpl_(new OwningModel<ShapeT, DrawStrategy>(std::move(shape),
                                                     std::move(drawer)),
               [](void* shapeBytes) {
                 // 呼び出し時に決まるModelの型情報から、正しい関数型を呼び出す
                 using Model = OwningModel<ShapeT, DrawStrategy>;
                 auto* const model = static_cast<Model*>(shapeBytes);
                 delete model;
               }),
        draw_([](void* shapeBytes) -> double {
          using Model = OwningModel<ShapeT, DrawStrategy>;
          auto* const model = static_cast<Model*>(shapeBytes);
          return (model->drawer_)(model->shape_);
        }),
        clone_([](void* shapeBytes) -> void* {
          using Model = OwningModel<ShapeT, DrawStrategy>;
          auto* const model = static_cast<Model const*>(shapeBytes);
          return new Model(*model);
        }) {}

  Shape(Shape const& other)
      : pimpl_(other.clone_(other.pimpl_.get()), other.pimpl_.get_deleter()),
        draw_(other.draw_),
        clone_(other.clone_) {}
  Shape& operator=(Shape const& other) {
    // Copy-and-Swap Idiom
    using std::swap;
    Shape copy(other);
    swap(pimpl_, copy.pimpl_);
    swap(draw_, copy.draw_);
    swap(clone_, copy.clone_);
    return *this;
  }
  ~Shape() = default;
  Shape(Shape&&) = default;
  Shape& operator=(Shape&&) = default;

 private:
  // Shape の持つ要件を定義する
  // 実装はPimplのラップとなる
  // 非メンバ関数とすることで、処理を分離する
  friend double draw(Shape const& shape) {
    return shape.draw_(shape.pimpl_.get());
  }

  template <typename ShapeT, typename DrawStrategy>
  struct OwningModel {
    OwningModel(ShapeT shape, DrawStrategy drawer)
        : shape_(std::move(shape)), drawer_(std::move(drawer)) {}

    ShapeT shape_;
    DrawStrategy drawer_;
  };

  using DestroyOperation = void(void*);
  using DrawOperation = double(void*);
  using CloneOperation = void*(void*);

  // void* として型情報を持たない
  // unique_ptr<T, Deleter>
  std::unique_ptr<void, DestroyOperation*> pimpl_;

  // Conceptを継承する代わりに、ポインタだけを持つ
  DrawOperation* draw_{nullptr};
  CloneOperation* clone_{nullptr};
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_SHAPE_H
