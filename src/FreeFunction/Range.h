#ifndef SRC_FREEFUNCTION_RANGE_H
#define SRC_FREEFUNCTION_RANGE_H

// フリー関数をメンバ関数より優先して使う理由：
// メンバ関数の追加は、既存コードを変更する必要がある上、追加できる型には制約がある。
// フリー関数(非メンバ関数)であれば、制約なしにどんな型へも追加することができる。

// 関数アダプタ begin(), end(): (Guideline 24)
// 任意の型のイテレータのインターフェースを、STLイテレータのインターフェースに変換する。
// フリー関数であるため、どんな型にも追加できる。

#include <iterator>

namespace FreeFunction {

// テンプレートパラメータ宣言の `typename` と `class`　は同じ意味。
// リテラルを期待するときは `typename` , ユーザ型を期待するときは `class`
// を使うことが多い。
template <class Range, class Function>
void traverseRange(Range const& range, Function const& function) {
  // std::begin() と FreeFunction::begin() をディスパッチする。
  using std::begin;
  using std::end;

  auto first{begin(range)};
  auto last{end(range)};
  for (; first != last; ++first) {
    function(*first);
  }
}

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
