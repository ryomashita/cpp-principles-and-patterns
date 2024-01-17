add_executable(WidgetTest WidgetTest.cpp)
target_include_directories(WidgetTest PRIVATE ${CMAKE_SOURCE_DIR}/src/HowToTestPrivateMethod)
enable_gtest(WidgetTest)