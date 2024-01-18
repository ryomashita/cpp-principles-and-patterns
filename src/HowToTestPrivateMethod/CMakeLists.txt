# Gudeline 4: how to test private methods

# Before
add_executable(WidgetBeforeTest ${CMAKE_CURRENT_SOURCE_DIR}/Before/WidgetTest.cpp)
target_include_directories(WidgetBeforeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Before)
enable_gtest(WidgetBeforeTest)
# After
add_executable(WidgetAfterTest ${CMAKE_CURRENT_SOURCE_DIR}/After/WidgetTest.cpp)
target_include_directories(WidgetAfterTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/After)
enable_gtest(WidgetAfterTest)