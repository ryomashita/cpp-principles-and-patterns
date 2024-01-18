#ifndef SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H
#define SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H

#include <cstdint>
#include <set>

/* ガイドライン４：privateメンバのテスト方法
 *　privateメンバをテストする方法には
 *    publicメソッドを介す/friendを使用する/protectedメンバに変更する
 *　などがあるが、いずれも製品コードの依存関係を複雑化させる。
 *
 * テストが必要(=重要なインターフェース)なメソッドは、別のクラス(依存関係)に切り出し、
 * publicメンバに変更することでテスト可能な状態にするのが正しい設計である。
 */

namespace HowToTestPrivateMethod {

using Blob = int32_t;

class BlobCollection {
 public:
  BlobCollection(std::set<Blob> blobs) : blobs_(std::move(blobs)){};
  auto updateCollection(std::set<Blob> blobs) {
    blobs_ = std::move(blobs);
    return blobs_.size();
  };

 private:
  std::set<Blob> blobs_;
};

class Widget {
 public:
  Widget(std::set<Blob> blobs) : blobs_(std::move(blobs)){};
  ~Widget() = default;

 private:
  auto updateCollection(std::set<Blob> blobs) {
    return blobs_.updateCollection(std::move(blobs));
  };

  BlobCollection blobs_;
};

}  // namespace HowToTestPrivateMethod

#endif  // SRC_HOWTOTESTPRIVATEMETHOD_WIDGET_H
