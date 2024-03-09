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

# SBO : SBOimized Implementation of Type Erasure Pattern
# SBO (Small Buffer SBOimization) and
# manual vtable implementation
# for details, see Shape.h
add_executable(TypeErasureSBOTest
  ${CMAKE_CURRENT_SOURCE_DIR}/SBO/TypeErasureShapeTest.cpp
)
target_include_directories(TypeErasureSBOTest
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SBO
)
set_normal_compile_options(TypeErasureSBOTest)
enable_gtest(TypeErasureSBOTest)