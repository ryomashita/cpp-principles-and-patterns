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
