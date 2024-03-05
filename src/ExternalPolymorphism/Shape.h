#ifndef SRC_STRATEGY_AFTER_SHAPE_H
#define SRC_STRATEGY_AFTER_SHAPE_H

#include <utility>

// External PolyMorphism Pattern
// 型に振る舞いを所有させる (Strategy Pattern) のではなく、
// 型と振る舞い(Concept)の組みとなるクラス (Model) を新たに定義することで、
// 型と振る舞いを完全に分離するデザインパターン。

namespace extpoly {

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
};

template <typename T, typename ShapeT>
concept DrawStrategyConcept = requires(const T& strategy, const ShapeT& shape) {
  { strategy(shape) } -> std::same_as<double>;
};

struct DefaultDrawer {
  template <typename ShapeT>
  double operator()(ShapeT const& shape) const {
    return draw(shape);
  }
};

template <typename ShapeT,
          DrawStrategyConcept<ShapeT> DrawStrategy = DefaultDrawer>
class ShapeModel : public ShapeConcept {
 public:
  explicit ShapeModel(ShapeT shape, DrawStrategy drawer)
      : shape_(std::move(shape)), drawer_(std::move(drawer)) {}

  double draw() const override { return drawer_(shape_); }

 private:
  ShapeT shape_;
  DrawStrategy drawer_;
};

}  // namespace extpoly

#endif  // SRC_STRATEGY_AFTER_SHAPE_H
