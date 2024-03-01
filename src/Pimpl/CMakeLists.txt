# Guideline 28 : Bridge Pattern (Pimpl Idiom)

# Pimpl
# for details, see Person.h
add_executable(PersonTest
  PersonTest.cpp
  Person.cpp
)
set_normal_compile_options(PersonTest)
enable_gtest(PersonTest)