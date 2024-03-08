#ifndef SRC_TYPEERASURE_BASE_SHAPE_H
#define SRC_TYPEERASURE_BASE_SHAPE_H

#include <utility>

// ユーザが直接使用しないことを示すため名前空間detailを使用
namespace typeerasure {

// Type Erasure Pattern
// External-Polymorphism Pattern を使い定義した Model (型と振る舞いの組み) を
// Pimpl (Bridge Pattern) で隠蔽することで、
// 型と振る舞いを分離しつつ、ShapeModelに型引数を渡す必要もなくなった。
// 更に 内部でclone()メソッド (Prototype Pattern) を使うことで、
// 値コピーを可能にし、値セマンティクスを実現した。

// SBO (Small Buffer Optimization) の適用：
// 予めバッファを確保することで、細かい動的メモリ割当によるオーバーヘッドを避ける。
// 動的メモリ割り当てを行う代わりに、メモリ戦略を注入できるようにした。
// std::construct_at, std::destroy_at を使うことで、
// 確保済みメモリ領域へのオブジェクト作成を、配置newより簡単に行える。

// 型消去されたShapeクラス：ShapeT, DrawStrategyの型情報を持たない
template <typename StoragePolicy>
class Shape {
 private:
  struct Concept {
    virtual ~Concept() = default;
    virtual double draw() const = 0;
    virtual Concept* clone(StoragePolicy const&) const = 0;
    virtual Concept* move(StoragePolicy const&) = 0;
  };

 public:
  template <typename ShapeT, typename DrawStrategy>
  Shape(ShapeT shape, DrawStrategy drawer) {
    using Model = OwningModel<ShapeT, DrawStrategy>;
    pimpl_ =
        policy_.template create<Model>(std::move(shape), std::move(drawer));
  }

  Shape(Shape const& other) : pimpl_(other.pimpl_->clone(policy_)) {}
  Shape& operator=(Shape const& other) {
    // Copy-and-Swap Idiom
    Shape copy(other);
    policy_.destroy(pimpl_);  // 既存のリソースを解放
    pimpl_ = other.pimpl_->clone(policy_);
    return *this;
  }
  Shape(Shape&& other) : pimpl_(other.pimpl_->move(policy_)) {}
  Shape& operator=(Shape&& other) noexcept {
    policy_.destroy(pimpl_);
    pimpl_ = other.pimpl_->move(policy_);
    return *this;
  }
  ~Shape() { policy_.destroy(pimpl_); }

 private:
  // Shape の持つ要件を定義する
  // 実装はPimplのラップとなる
  // 非メンバ関数とすることで、処理を分離する
  friend double draw(Shape const& shape) { return shape.pimpl_->draw(); }

  // 実装詳細はPimplに隠蔽されるため、Shape自身はShape,
  // DrawStrategyの型情報を一切持たない。
  // そのため型消去 (Type Erasure) と呼ばれる。
  // std::unique_ptr<detail::ShapeConcept> pimpl_;  // Bridge Pattern

  // OwningShapeModel: 型(ShapeT)と振る舞い(DrawStrategy)の結びつきを定義する。
  template <typename ShapeT, typename DrawStrategy>
  class OwningModel : public Concept {
   public:
    explicit OwningModel(ShapeT shape, DrawStrategy drawer)
        : shape_(std::move(shape)), drawer_(std::move(drawer)) {}
    double draw() const override { return drawer_(shape_); }
    Concept* clone(StoragePolicy const& policy) const override {
      // policy 内で constructor(*this) を呼び出す
      return policy.template create<OwningModel>(*this);
    }
    Concept* move(StoragePolicy const& policy) override {
      return policy.template create<OwningModel>(std::move(*this));
    }

   private:
    ShapeT shape_;
    DrawStrategy drawer_;
  };

  // no_unique_address:
  // 空オブジェクトがアドレスを持たない(メモリを割り当てなくて良い)ことを示す
  [[no_unique_address]] StoragePolicy policy_{};
  Concept* pimpl_{};
};

}  // namespace typeerasure

#endif  // SRC_TYPEERASURE_BASE_SHAPE_H
