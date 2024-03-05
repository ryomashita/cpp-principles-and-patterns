function(set_target_cxx20 target)
  target_compile_features(${target} PRIVATE cxx_std_20)
endfunction()

function(set_normal_compile_options target)
  # Set Language Standard
  set_target_cxx20(${target})  

  # Set Compile Options
  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++ (/W4) # 例: 警告レベルを設定
    target_compile_options(${target} PRIVATE /DWIN32 /D_WINDOWS /D_MSBC /W4 /WX- /nologo /fp:precise /arch:AVX2 /Zc:wchar_t /TP /Gd)
    target_compile_options(${target} PRIVATE $<$<CONFIG:Release>:/MD /O2 /GL /GR- /DNDEBUG>)
    target_compile_options(${target} PRIVATE $<$<CONFIG:Debug>:/D_DEBUG /MDd /Zi /Ob0 /Od /RTC1 /Gy /GR- /GS /Gm-)
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic) # 例: 警告オプションを設定
    target_compile_options(${target} PRIVATE -O2)
    # target_compile_options(${target} PRIVATE -g)
    target_compile_options(${target} PRIVATE -std=c++20 -std=gnu++20 -march=x86-64-v3)
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
  else()
    message(FATAL_ERROR "Unknow compiler")
  endif()
endfunction()
