add_library(
  Task1Dir STATIC
  Task1.h
  Task1.cpp
  Functions1.cpp
  Menus1.cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSESW REQUIRED ncursesw)
include_directories(${NCURSESW_INCLUDE_DIRS})

target_include_directories(Task1Dir PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})