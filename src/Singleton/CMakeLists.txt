# Guideline 38 : Singleton Pattern

# Singleton Pattern
# for details, see PersistenceInterface.h
add_executable(SingletonTest
  PersistenceInterface.cpp
  SingletonTest.cpp
)
set_normal_compile_options(SingletonTest)
enable_gtest(SingletonTest)