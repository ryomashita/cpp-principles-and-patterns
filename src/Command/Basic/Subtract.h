#ifndef SRC_COMMAND_BASIC_SUBTRACT_H
#define SRC_COMMAND_BASIC_SUBTRACT_H

#include "CalculatorCommand.h"

namespace command {
class Subtract : public CalculatorCommand {
 public:
  explicit Subtract(int operand) : operand_(operand) {}

  int execute(int value) const override { return value - operand_; }
  int undo(int value) const override { return value + operand_; }

 private:
  int operand_{};
};

}  // namespace command

#endif  // SRC_COMMAND_BASIC_SUBTRACT_H
