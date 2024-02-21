# Guidline 25 : Observer Pattern

# Value (Value Semantics Based)
# For futher information, see Value/Observer.h
add_executable(ObserverValueTest
  ${CMAKE_CURRENT_SOURCE_DIR}/Value/PersonObserverTest.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Value/Person.cpp
)
target_include_directories(ObserverValueTest PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Value
)
set_normal_compile_options(ObserverValueTest)
enable_gtest(ObserverValueTest)