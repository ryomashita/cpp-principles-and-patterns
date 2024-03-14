#ifndef SRC_SINGLETON_DATABASE_H
#define SRC_SINGLETON_DATABASE_H

#include "PersistenceInterface.h"
#include <map>

namespace singleton {

namespace {
  // サンプルコード用のデータ
  std::map<uint64_t, uint64_t> database;
}

class DataBase : public PersistenceInterface {
 public:
  DataBase() = default;

  // Singleton表現のため コピー/ムーブ禁止
  DataBase(DataBase const&) = delete;
  DataBase& operator=(DataBase const&) = delete;
  DataBase(DataBase&&) = delete;
  DataBase& operator=(DataBase&&) = delete;

 private:
  bool do_read(const uint64_t address, uint64_t& data) const override {
    data = database[address];
    return true;
  }
  bool do_write(const uint64_t address, uint64_t data) const override {
    database[address] = data;
    return true;
  }
};

} // namespace singleton

#endif // SRC_SINGLETON_DATABASE_H
