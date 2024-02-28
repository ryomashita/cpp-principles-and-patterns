# Guideline 26 : CRTP Pattern

# Before (Not using Design Pattern)
add_executable(CrtpBeforeTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/Before/DenseVectorTest.cpp
)
target_include_directories(CrtpBeforeTest PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}
)
set_normal_compile_options(CrtpBeforeTest)
enable_gtest(CrtpBeforeTest)

# After (Using CRTP Pattern with C++20 Concepts)
# for details, see DenseVector.h
add_executable(CrtpAfterTest 
  ${CMAKE_CURRENT_SOURCE_DIR}/After/DenseVectorTest.cpp
)
target_include_directories(CrtpAfterTest PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}
)
set_normal_compile_options(CrtpAfterTest)
enable_gtest(CrtpAfterTest)