#ifndef SRC_COMMAND_BASIC_SUBTRACT_H
#define SRC_COMMAND_BASIC_SUBTRACT_H

#include <functional>

namespace command {
class Subtract {
 public:
  using ExecuteCommand = std::function<int(int)>;
  using UndoCommand = std::function<int(int)>;
  using CalculateCommandSet = std::pair<ExecuteCommand, UndoCommand>;

  explicit Subtract(int operand) : operand_(operand) {}

  CalculateCommandSet command_set() const {
    return {execute_command(operand_), undo_command(operand_)};
  }
  ExecuteCommand execute_command(int operand) const {
    return [operand](int value) { return value - operand; };
  }
  UndoCommand undo_command(int operand) const {
    return [operand](int value) { return value + operand; };
  }

 private:
  int operand_{};
};

}  // namespace command

#endif  // SRC_COMMAND_BASIC_SUBTRACT_H
