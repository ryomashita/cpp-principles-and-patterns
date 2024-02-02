#ifndef SRC_VISITOR_PROCEDURAL_DRAWALLSHAPES_H
#define SRC_VISITOR_PROCEDURAL_DRAWALLSHAPES_H

#include <memory>
#include <vector>

namespace visitor {
class Shape;

double GetAllArea(std::vector<std::shared_ptr<Shape>> const& shapes);

}  // namespace visitor

#endif  // SRC_VISITOR_PROCEDURAL_DRAWALLSHAPES_H
