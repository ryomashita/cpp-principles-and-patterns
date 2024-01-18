# Gudeline 4: how to test private methods

# Before
add_executable(WidgetBeforeTest ${CMAKE_CURRENT_SOURCE_DIR}/Before/WidgetTest.cpp)
target_include_directories(WidgetBeforeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Before)
set_normal_compile_options(WidgetBeforeTest)
enable_gtest(WidgetBeforeTest)
# After
add_executable(WidgetAfterTest ${CMAKE_CURRENT_SOURCE_DIR}/After/WidgetTest.cpp)
target_include_directories(WidgetAfterTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/After)
set_normal_compile_options(WidgetAfterTest)
enable_gtest(WidgetAfterTest)