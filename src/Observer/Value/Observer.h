#ifndef SRC_OBSERVER_OBSERVER_H
#define SRC_OBSERVER_OBSERVER_H
#include <functional>
#include <string>

// Observer Pattern (Value Semantics Based):
// イベントの発生時に update() で呼び出すコールバックを std::function
// で注入する。 イベント種別は enum, Observer のIDは
// オブジェクトのポインタで識別する。 書籍の実装は update() を1つしか持たない
// プルオブザーバ でのみ機能する。
// 他にもObserverの実装には様々な要求、問題があるが、本書では詳細を述べることは避けている。

namespace observer {
template <typename Subject, typename StateTag>
class Observer {
 public:
  using OnUpdate = std::function<std::string(Subject const&, StateTag)>;

  explicit Observer(OnUpdate onUpdate) : onUpdate_(std::move(onUpdate)) {}

  void update(Subject const& subject, StateTag property) {
    std::string changedState = onUpdate_(subject, property);
    if (changedState != std::string{}) {
      state_ = std::move(changedState);
    }
  }
  std::string const& state() const { return state_; }

 private:
  OnUpdate onUpdate_;
  std::string state_;
};
}  // namespace observer

#endif  // SRC_OBSERVER_OBSERVER_H
