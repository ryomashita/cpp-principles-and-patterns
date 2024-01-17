add_library(Widget SHARED Widget_Before.h)
set_target_properties(Widget PROPERTIES LINKER_LANGUAGE CXX)
set_normal_compile_options(Widget)