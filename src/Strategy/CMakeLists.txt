# Guideline 19: Strategy Pattern

# After (Correct implementation)
# For futher description, see After/Circle.h
add_executable(StrategyAfterTest
  ${CMAKE_CURRENT_SOURCE_DIR}/After/SpecificStrategyTest.cpp
)
target_include_directories(StrategyAfterTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/After
)
set_normal_compile_options(StrategyAfterTest)
enable_gtest(StrategyAfterTest)

# Value (Value Semantics Based)
# For futher description, see Value/Circle.h
add_executable(StrategyValueTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Value/SpecificStrategyTest.cpp
)
target_include_directories(StrategyValueTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Value
)
set_normal_compile_options(StrategyValueTest)
enable_gtest(StrategyValueTest)