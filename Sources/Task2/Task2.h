#ifndef TASK_1_HEADER
#define TASK_1_HEADER

#pragma once

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std::chrono_literals;

const char filename[33] = "../Sources/Task2/RailwayInfo.txt";

typedef struct Train {
  std::string Date;
  std::string Destination;
  union number {
    int Places;
  } number;
} Train;

extern Train* trains;
extern int size2;

void WriteToFile2(Train*&);
void ReadFromFile2(Train*&);
void ResizingArray(Train*&);

void OutputTerminal();

#endif
