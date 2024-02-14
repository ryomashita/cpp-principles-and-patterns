# Guidline 21, 23 : Command Pattern

# Basic (Good Implementation, but refactored later with value-semantics)
# For futher information, see Basic/Calculator.h
add_executable(CommandBasicTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Basic/CalculatorTest.cpp
)
target_include_directories(CommandBasicTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Basic
)
set_normal_compile_options(CommandBasicTest)
enable_gtest(CommandBasicTest)

# Value (Value Semantics Based)
# For futher information, see Value/Calculator.h
add_executable(CommandValueTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Value/CalculatorTest.cpp
)
target_include_directories(CommandValueTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Value
)
set_normal_compile_options(CommandValueTest)
enable_gtest(CommandValueTest)