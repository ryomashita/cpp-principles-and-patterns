#ifndef SRC_TYPEERASURE_BASE_SHAPE_H
#define SRC_TYPEERASURE_BASE_SHAPE_H

#include <memory>
#include <utility>

// ユーザが直接使用しないことを示すため名前空間detailを使用
namespace typeerasure {

namespace detail {

// Type Erasure Pattern
// External-Polymorphism Pattern を使い定義した Model (型と振る舞いの組み) を
// Pimpl (Bridge Pattern) で隠蔽することで、
// 型と振る舞いを分離しつつ、ShapeModelに型引数を渡す必要もなくなった。
// 更に 内部でclone()メソッド (Prototype Pattern) を使うことで、
// 値コピーを可能にし、値セマンティクスを実現した。

class ShapeConcept {
 public:
  // サブクラスのdestructorが呼ばれるように、
  // 基底クラスのデストラクタは
  // - public & virtual
  // - protected & non-virtual
  // - final & public & non-virtual
  // のいずれかとする
  virtual ~ShapeConcept() = default;
  virtual double draw() const = 0;
  virtual std::unique_ptr<ShapeConcept> clone() const = 0;  // Prototype Pattern
};

// OwningShapeModel: 型(ShapeT)と振る舞い(DrawStrategy)の結びつきを定義する。
template <typename ShapeT, typename DrawStrategy>
class OwningShapeModel : public ShapeConcept {
 public:
  explicit OwningShapeModel(ShapeT shape, DrawStrategy drawer)
      : shape_(std::move(shape)), drawer_(std::move(drawer)) {}

  double draw() const override { return drawer_(shape_); }

  std::unique_ptr<ShapeConcept> clone() const override {
    return std::make_unique<OwningShapeModel>(*this);
  }

 private:
  ShapeT shape_;
  DrawStrategy drawer_;
};

}  // namespace detail

// 型消去されたShapeクラス：ShapeT, DrawStrategyの型情報を持たない
class Shape {
 public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer) {
    using Model = detail::OwningShapeModel<ShapeT, DrawStrategy>;
    pimpl_ = std::make_unique<Model>(std::move(shape), std::move(drawer));
  }

  Shape(Shape const& other) : pimpl_(other.pimpl_->clone()) {}
  Shape& operator=(Shape const& other) {
    // Copy-and-Swap Idiom
    Shape copy(other);
    pimpl_.swap(copy.pimpl_);
    return *this;
  }
  ~Shape() = default;
  Shape(Shape&&) = default;
  Shape& operator=(Shape&&) = default;

 private:
  // Shape の持つ要件を定義する
  // 実装はPimplのラップとなる
  // 非メンバ関数とすることで、処理を分離する
  friend double draw(Shape const& shape) { return shape.pimpl_->draw(); }

  // 実装詳細はPimplに隠蔽されるため、Shape自身はShape,
  // DrawStrategyの型情報を一切持たない。
  // そのため型消去 (Type Erasure) と呼ばれる。
  std::unique_ptr<detail::ShapeConcept> pimpl_;  // Bridge Pattern
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_SHAPE_H
