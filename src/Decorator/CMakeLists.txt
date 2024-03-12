# Guideline 35 - 36 : Decorator Pattern

# Template : Compilt-time Abstraction of Decorator Pattern
# for details, see Template/PricedItem.h
add_executable(DecoratorTemplateTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/Template/DecoratorTest.cpp
)
target_include_directories(DecoratorTemplateTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Template
)
set_normal_compile_options(DecoratorTemplateTest)
enable_gtest(DecoratorTemplateTest)

# TypeErasure : Runtime Abstraction of Decorator Pattern
# for details, see Item.h
add_executable(DecoratorTypeErasureTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/TypeErasure/DecoratorTest.cpp
)
target_include_directories(DecoratorTypeErasureTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/TypeErasure
)
set_normal_compile_options(DecoratorTypeErasureTest)
enable_gtest(DecoratorTypeErasureTest)