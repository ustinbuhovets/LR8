#ifndef TASK_1_HEADER
#define TASK_1_HEADER

#pragma once

#include <iostream>
#include <unistd.h>
#include <ncursesw/ncurses.h>
#include <locale.h>
#include <thread>
#include <chrono>
#include <cstring>
#include <fstream>

using namespace std::chrono_literals;

const int ESCAPE = 27, ENTER = 10, DOWN_KEY = 258, UP_KEY = 259;
const char filename[27] = "../Sources/Task1/BusesInfo";

typedef struct Bus {
  char Number[5];
  wchar_t Type[80];
  wchar_t Destination[80];
  wchar_t DepartationTime[10];
  wchar_t ArrivingTime[10];
} Bus;

extern Bus* buses;

int BusTerminal();

void ErrorMessage();
void WriteToFile(Bus*&);
void ReadFromFile(Bus*&);
void InitializeBuses(Bus*&);
void OutputBusesInfo(Bus*&);
void FindFlight(Bus*&, int);

#endif
