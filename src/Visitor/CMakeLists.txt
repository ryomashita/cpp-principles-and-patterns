# Guideline 15 - 18: Visitor Pattern

# Before (Procedural Programming's Sample)
# see description in DrawAllShapes.cpp
add_executable(VisitorBeforeTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/Procedural/DrawCircle.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Procedural/DrawSquare.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Procedural/DrawAllShapes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Procedural/DrawTest.cpp
)
target_include_directories(VisitorBeforeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Procedual)
set_normal_compile_options(VisitorBeforeTest)
enable_gtest(VisitorBeforeTest)

# After (The Solution with std::variant)
# see description in DrawAllShapes.cpp
add_executable(VisitorAfterTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/Variant/DrawAllShapes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Variant/DrawTest.cpp
)
target_include_directories(VisitorAfterTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Variant)
set_normal_compile_options(VisitorAfterTest)
enable_gtest(VisitorAfterTest)