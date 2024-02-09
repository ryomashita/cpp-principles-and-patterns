# Guidline 21, 23 : Command Pattern

# Basic (Good Implementation, but refactored later with value-semantics)
add_executable(CommandBasicTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Basic/CalculatorTest.cpp
)
target_include_directories(CommandBasicTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Basic
)
set_normal_compile_options(CommandBasicTest)
enable_gtest(CommandBasicTest)
