#ifndef SRC_COMMAND_BASIC_ADD_H
#define SRC_COMMAND_BASIC_ADD_H

#include <functional>

namespace command {
class Add {
 public:
  using ExecuteCommand = std::function<int(int)>;
  using UndoCommand = std::function<int(int)>;
  using CalculateCommandSet = std::pair<ExecuteCommand, UndoCommand>;

  explicit Add(int operand) : operand_(operand) {}

  CalculateCommandSet command_set() const {
    return {execute_command(operand_), undo_command(operand_)};
  }
  ExecuteCommand execute_command(int operand) const {
    return [operand](int value) { return value + operand; };
  }
  UndoCommand undo_command(int operand) const {
    return [operand](int value) { return value - operand; };
  }

 private:
  int operand_{};
};

}  // namespace command

#endif  // SRC_COMMAND_BASIC_ADD_H
