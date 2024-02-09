#ifndef SRC_COMMAND_BASIC_CALCULATOR_H
#define SRC_COMMAND_BASIC_CALCULATOR_H

#include <memory>
#include <stack>

#include "CalculatorCommand.h"

// Command Pattern:
// Strategyと同様、単一の処理を抽象化(CalculatorCommand)し、他のオブジェクトに注入する。
// これにより処理の追加が容易になる。
// Strategyでは処理がどのような(How)ものかを注入先が知っているのに対し、
// Commandでは、注入先は処理の内容を一切知る必要がない。（よりカプセル化されている）
// 一方でStrategy同様、処理(Commandクラス)の追加は困難。

namespace command {
class Calculator {
 public:
  void compute(std::unique_ptr<CalculatorCommand> command) {
    current_ = command->execute(current_);
    stack_.push(std::move(command));
  }
  void undoLast() {
    if (stack_.empty()) return;

    auto command = std::move(stack_.top());
    stack_.pop();

    current_ = command->undo(current_);
  }

  int result() const { return current_; }
  void clear() {
    current_ = 0;
    CommandStack{}.swap(stack_);
    // std::stack::swap() : オブジェクトを入れ替える
    // 単に代入するのと異なり、オブジェクトは破棄されず、内容のみが入れ替えられる
    // そのためオブジェクトが別の場所から参照されている場合も、その参照が壊れることはない
  }

 private:
  using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;
  int current_{};
  CommandStack stack_;
};
}  // namespace command

#endif  // SRC_COMMAND_BASIC_CALCULATOR_H
