# Guideline 32 : Type Erasure Pattern

# Base : Simple Implementation of Type Erasure Pattern
# for details, see Shape.h
add_executable(TypeErasureBaseTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/TypeErasureShapeTest.cpp
)
target_include_directories(TypeErasureBaseTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Base
)
set_normal_compile_options(TypeErasureBaseTest)
enable_gtest(TypeErasureBaseTest)

# Opt : Optimized Implementation of Type Erasure Pattern
# SBO (Small Buffer Optimization) and
# manual vtable implementation
# for details, see Shape.h
add_executable(TypeErasureOptTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Opt/TypeErasureShapeTest.cpp
)
target_include_directories(TypeErasureOptTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Opt
)
set_normal_compile_options(TypeErasureOptTest)
enable_gtest(TypeErasureOptTest)