#include <Task1.h>

void Line1();
/*  Bus Terminal Functions  */
void OutputTerminalText(int);
void Buses(int);
void FindTheBusFlight(int);
void AddInfo(int);
void RemoveInfo(int);
void SortBuses(int);
void Exit(int);
/*  Buses Menu Functions  */
void BusesMenu(int&);
void FindFlightMenu(int&);
void AddInfoMenu();
void RemoveInfoMenu();

int BusTerminal() {
  int Status = 1, EnterFlag = 0, ch = 0;
  OutputTerminalText(Status);
  while ((ch = getch()) != ESCAPE) {
    std::this_thread::sleep_for(30ms);
    switch(ch) {
      case DOWN_KEY:
        if (Status < 6) {
          ++Status;
          EnterFlag = 0;
        }
        break;
      case UP_KEY:
        if (Status > 1) {
          --Status;
          EnterFlag = 0;
        }
        break;
      case ENTER:
        if (EnterFlag < 2) {
          ++EnterFlag;
        }
        break;
      default:
        break;
    }

    if (EnterFlag) {
      switch(Status) {
        case 1:
          BusesMenu(EnterFlag);
          break;
        case 2:
          FindFlightMenu(EnterFlag);
          break;
        case 5:
          break;
        default:
          break;
      }
    }
    if (!EnterFlag) {
      OutputTerminalText(Status);
    }

    if (Status == 6 && EnterFlag) {
      clear();
      printw("\n\t   <  Завершение работы...  >");
      refresh();
      std::this_thread::sleep_for(500ms);
      break;
    }
  }

  if ((Status == 6 && EnterFlag) || ch == ESCAPE) {
    endwin();
    system("clear");
    std::cout << "Вы вышли из программы.\n";
    return 0;
  }

  endwin();
  return 0;
}

void OutputTerminalText(int Status) {
  clear();
  printw("Табло автовокзала. Здесь вы можете посмотреть интересующую вас информацию о предстоящих рейсах:\n");
  Buses(Status);
  FindTheBusFlight(Status);
  AddInfo(Status);
  RemoveInfo(Status);
  SortBuses(Status);
  Exit(Status);
}

void Buses(int Status) {
  std::string Addition = (Status == 1) ? ">  Автобусы  <" : "   Автобусы";
  printw("1. %s\n", Addition.c_str());
}

void FindTheBusFlight(int Status) {
  std::string Addition = (Status == 2) ? ">  Найти рейс  <" : "   Найти рейс";
  printw("2. %s\n", Addition.c_str());
}

void AddInfo(int Status) {
  std::string Addition = (Status == 3) ? ">  Добавить рейс  <" : "   Добавить рейс";
  printw("3. %s\n", Addition.c_str());
}

void RemoveInfo(int Status) {
  std::string Addition = (Status == 4) ? ">  Удалить рейс  <" : "   Удалить рейс";
  printw("4. %s\n", Addition.c_str());
}

void SortBuses(int Status) {
  std::string Addition = (Status == 5) ? ">  Отсортировать  <" : "   Отсортировать";
  printw("5. %s\n", Addition.c_str());
}

void Exit(int Status) {
  std::string Addition = (Status == 6) ? ">  Выход  <" : "   Выход";
  printw("6. %s\n", Addition.c_str());
}

/*  Watching Buses Menu  */
void BusesMenu(int& EnterFlag) {
  clear();
  printw("  Доступные рейсы автобусов:\n");
  Line1();
  printw("|   Номер   |    Тип автобуса     |  Пункт назначения   | Время  | Время  |\n");
  Line1();
  OutputBusesInfo(buses);
  Line1();
  printw("  Вернуться. (Enter)");
  if (EnterFlag == 2) {
    EnterFlag = 0;
  }
}

/*  Finding the Bus Flight  */
void FindFlightMenuText(int NewStatus) {
  clear();
  printw(" По какой опции желаете найти рейс?\n");
  std::string Addition = (NewStatus == 1) ? ">  Номер  <" : "   Номер";
  printw("1. %s\n", Addition.c_str());
  Addition = (NewStatus == 2) ? ">  Тип автобуса  <" : "   Тип автобуса";
  printw("2. %s\n", Addition.c_str());
  Addition = (NewStatus == 3) ? ">  Пункт назначения  <" : "   Пункт назначения";
  printw("3. %s\n", Addition.c_str());
  Addition = (NewStatus == 4) ? ">  Время выезда  <" : "   Время выезда";
  printw("4. %s\n", Addition.c_str());
  Addition = (NewStatus == 5) ? ">  Время прибытия  <" : "   Время прибытия";
  printw("5. %s\n", Addition.c_str());
  Addition = (NewStatus == 6) ? "> Вернуться <" : "  Вернуться";
  printw("\n %s\n", Addition.c_str());
}

void FindFlightMenu(int& EnterFlag) {
  int ch = 0, NewStatus = 1;
  FindFlightMenuText(NewStatus);
  while ((ch = getch()) != ESCAPE) {
    switch(ch) {
      case DOWN_KEY:
        if (NewStatus < 6) {
          ++NewStatus;
        }
        break;
      case UP_KEY:
        if (NewStatus > 1) {
          --NewStatus;
        }
        break;
      case ENTER:
        if (EnterFlag < 2) {
          ++EnterFlag;
        }
        break;
      default:
        break;
    }

    if (EnterFlag == 1) {
      FindFlightMenuText(NewStatus);
    }
    if (EnterFlag == 2) {
      if (NewStatus == 6) {
        EnterFlag = 0;
        break;
      }
      FindFlight(buses, NewStatus);
    }
  }

  EnterFlag = 0;
}


void Line1() {
  printw("----------------------------------------------------------------------------\n");
}