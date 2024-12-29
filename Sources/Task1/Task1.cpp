#include <Task1.h>

Bus* buses = (Bus*)malloc(5 * sizeof(Bus));

void Task1() {
  setlocale(LC_ALL, "");
  // Ncurses Initialization
  initscr();
  raw();
  keypad(stdscr, TRUE);
  echo();

  ReadFromFile(buses);
  BusTerminal();
}
