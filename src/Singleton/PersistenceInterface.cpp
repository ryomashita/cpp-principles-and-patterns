#include "PersistenceInterface.h"

#include "Database.h"

namespace singleton {

PersistenceInterface* get_persistence_instance() {
  // static : 静的ローカル変数 -> 最初の関数呼出時に初期化される。
  // () : ラムダを定義すると同時に実行する。
  // => IILE (Immediately Invoked Lambda Expression)
  // 関数の初回呼出時にのみ呼び出されるラムダ式となる。

  // clangdの警告を回避するため[[maybe_unused]]を使用。
  [[maybe_unused]] static bool init_global_persistence = []() {
    if (global_persistence == nullptr) {
      global_persistence = new DataBase();
    }
    return true;
  }();

  return global_persistence;
}

void set_persistence_instance(PersistenceInterface* persistence) {
  global_persistence = persistence;
}

}  // namespace singleton