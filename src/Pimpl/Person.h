#ifndef SRC_PIMPL_PERSON_H
#define SRC_PIMPL_PERSON_H

#include <memory>

// Bridge Pattern :
// クラス・データの物理的な（ファイルの）依存関係を分離することを目的に、
// 抽象化を行うデザインパターン。

// Pimple イディオム :
// Pimpl イディオムでは特に、プライベートメンバを構造体に隠蔽することで、
// インクルードファイルとプライベートメンバの定義を分離する。

// Pimplを単純に使うと、Pimpl構造体を介することでオーバーヘッドが予想される。
// しかし高頻度のアクセスが予想されるメンバ変数はPimpl構造体の対象外とすることで、
// クラスのサイズ減少により、却ってパフォーマンスが向上する場合もある。
// (実際にはベンチマークを必ず取るべき。)

namespace pimpl {

class Person {
 public:
  Person();
  ~Person();
  Person(Person const& other);
  Person& operator=(const Person& other);
  Person(Person&& other) noexcept;
  Person& operator=(Person&& other) noexcept;

  int year_of_birth() const;
  void set_year_of_birth(int year);

 private:
  // 高頻度のアクセスが予想されるメンバ変数は、
  // Pimpl イディオムの対象外とする
  std::string forename;
  std::string surname;

  struct Impl;  // Implクラスの前方宣言
  std::unique_ptr<Impl> pimpl_;
};

}  // namespace pimpl

#endif  // SRC_PIMPL_PERSON_H
