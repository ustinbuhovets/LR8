add_subdirectory(Task1)
# add_subdirectory(Task2)

add_library(
  StaticLibLR8 STATIC
  StaticLibLR8.h
  ContextMenu.cpp
  ImplementingTasks.cpp
  Task1/Task1.cpp
  Task2/Task2.cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSESW REQUIRED ncursesw)
include_directories(${NCURSESW_INCLUDE_DIRS})

target_link_libraries(StaticLibLR8 ${NCURSESW_LIBRARIES} Task1Dir)

target_include_directories(StaticLibLR8 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
