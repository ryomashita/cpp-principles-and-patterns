#ifndef SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H
#define SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H

#include <cstdint>
#include <set>

namespace HowToTestPrivateMethod {

using Blob = int32_t;

class Widget {
 public:
  Widget(std::set<Blob> blobs) : blobs_(std::move(blobs)){};
  ~Widget() = default;

 private:
  auto updateCollection(std::set<Blob> blobs) {
    blobs_ = std::move(blobs);
    return blobs_.size();
  };
  std::set<Blob> blobs_;

 public:
  friend class WidgetTestFriend;
};

}  // namespace HowToTestPrivateMethod

#endif  // SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H
