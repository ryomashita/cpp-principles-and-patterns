# Guideline 8: The powe of free functions

# RangeTest
add_executable(RangeTest ${CMAKE_CURRENT_SOURCE_DIR}/RangeTest.cpp)
target_include_directories(RangeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
set_normal_compile_options(RangeTest)
enable_gtest(RangeTest)