add_library(
  Task2Dir STATIC
  Task2.h
  Task2.cpp
  Functions2.cpp
  Menus2.cpp
)

# find_package(PkgConfig REQUIRED)
# pkg_check_modules(NCURSESW REQUIRED ncursesw)
# include_directories(${NCURSESW_INCLUDE_DIRS})

target_include_directories(Task2Dir PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})