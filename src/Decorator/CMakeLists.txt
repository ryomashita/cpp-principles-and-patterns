# Guideline 35 - 36 : Decorator Pattern

# Template : Compilt-time Abstraction of Decorator Pattern
add_executable(DecoratorTemplateTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/Template/DecoratorTest.cpp
)
target_include_directories(DecoratorTemplateTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Template
)
set_normal_compile_options(DecoratorTemplateTest)
enable_gtest(DecoratorTemplateTest)