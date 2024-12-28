// Header file of Static Library for laboratory work 8

#ifndef STATIC_LIB_LR8_HEADER
#define STATIC_LIB_LR8_HEADER

#pragma once

#include <iostream>
#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

const int ESCAPE = 27, ENTER = 10, DOWN_KEY = 258, UP_KEY = 259;

int OutputContextMenu();
void ImplementingTasks();
void Line();

void Task1();

void Task2();

#endif
