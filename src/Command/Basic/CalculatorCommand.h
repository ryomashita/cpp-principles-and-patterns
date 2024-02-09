#ifndef SRC_COMMAND_BASIC_CALCULATORCOMMAND_H
#define SRC_COMMAND_BASIC_CALCULATORCOMMAND_H

namespace command {
class CalculatorCommand {
 public:
  virtual ~CalculatorCommand() = default;

  virtual int execute(int value) const = 0;
  virtual int undo(int value) const = 0;
};

}  // namespace command

#endif  // SRC_COMMAND_BASIC_CALCULATORCOMMAND_H
