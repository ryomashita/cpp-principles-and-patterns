#ifndef SRC_VISITOR_PROCEDURAL_SHAPE_H
#define SRC_VISITOR_PROCEDURAL_SHAPE_H

namespace visitor {

enum class ShapeType { circle, square };

class Shape {
 protected:
  explicit Shape(ShapeType type) : type_(type) {}

 public:
  virtual ~Shape() = default;

  ShapeType getType() const { return type_; }

 private:
  ShapeType type_;
};

}  // namespace visitor

#endif  // SRC_VISITOR_PROCEDURAL_SHAPE_H
