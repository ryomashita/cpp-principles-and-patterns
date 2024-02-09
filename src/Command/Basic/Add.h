#ifndef SRC_COMMAND_BASIC_ADD_H
#define SRC_COMMAND_BASIC_ADD_H

#include "CalculatorCommand.h"

namespace command {
class Add : public CalculatorCommand {
 public:
  explicit Add(int operand) : operand_(operand) {}

  int execute(int value) const override { return value + operand_; }
  int undo(int value) const override { return value - operand_; }

 private:
  int operand_{};
};

}  // namespace command

#endif  // SRC_COMMAND_BASIC_ADD_H
