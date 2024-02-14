#ifndef SRC_COMMAND_BASIC_CALCULATOR_H
#define SRC_COMMAND_BASIC_CALCULATOR_H

#include <functional>
#include <stack>

// Command Pattern (Value Semantic Based):
// Strategyと同様、Commandを値セマンティクス(std::function)で注入するよう改善。
// 依存オブジェクトの抽象化により、Strategyとの差はほとんどなくなった。

namespace command {
class Calculator {
 public:
  using ExecuteCommand = std::function<int(int)>;
  using UndoCommand = std::function<int(int)>;
  using CalculateCommandSet = std::pair<ExecuteCommand, UndoCommand>;

  void compute(CalculateCommandSet command) {
    current_ = command.first(current_);
    stack_.push(std::move(command));
  }
  void undoLast() {
    if (stack_.empty()) return;

    auto command = std::move(stack_.top());
    stack_.pop();

    current_ = command.second(current_);
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
  using CommandStack = std::stack<CalculateCommandSet>;
  int current_{};
  CommandStack stack_;
};
}  // namespace command

#endif  // SRC_COMMAND_BASIC_CALCULATOR_H
