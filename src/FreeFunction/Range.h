#ifndef SRC_FREEFUNCTION_RANGE_H
#define SRC_FREEFUNCTION_RANGE_H

namespace FreeFunction {

// テンプレートパラメータの宣言における `typename` と `class`　は同じ意味。
// リテラルを期待するときは `typename` , ユーザ型を期待するときは `class`
// を使う。

template <class Range, class Function>
void traverseRange(Range const& range, Function const& function) {
  using std::begin;
  using std::end;

  for (auto pos = begin(range); pos != end(range); ++pos) {
    function(*pos);
  }
}

// メンバ関数の追加は、既存コードを変更する必要がある上、追加できる型には制約がある。
// フリー関数(非メンバ関数)であれば、制約なしにどんな型へも追加することができる。
template <class T>
auto begin(const T (&arr)[]) {
  return std::cbegin(arr);
}

template <class T>
auto end(const T (&arr)[]) {
  return std::cend(arr);
}

}  // namespace FreeFunction

#endif  // SRC_FREEFUNCTION_RANGE_H
