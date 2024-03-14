#ifndef SRC_SINGLETON_PERSISTENCEINTERFACE_H
#define SRC_SINGLETON_PERSISTENCEINTERFACE_H

#include <cstdint>

// Singleton Pattern :
// グローバルな状態を持つ型の実装パターン
// インターフェースの抽出を行い、
// その実装をグローバルなsetter/getterで注入できるようにする。
// c.f., std::pmr::memory_resource

// 初期化(最初のset)を必ず行うため、
// get_* 内で静的ローカルなラムダ式を使い、初期化を実行している。

namespace singleton {

class PersistenceInterface {
 public:
  virtual ~PersistenceInterface() = default;

  bool read(const uint64_t address, uint64_t& data) const {
    return do_read(address, data);
  }
  bool write(const uint64_t address, uint64_t data) const {
    return do_write(address, data);
  }

 private:
  virtual bool do_read(const uint64_t address, uint64_t& data) const = 0;
  virtual bool do_write(const uint64_t address, uint64_t data) const = 0;
};

PersistenceInterface* get_persistence_instance();
void set_persistence_instance(PersistenceInterface* persistence);

inline PersistenceInterface* global_persistence = nullptr;

}  // namespace singleton

#endif  // SRC_SINGLETON_PERSISTENCEINTERFACE_H
