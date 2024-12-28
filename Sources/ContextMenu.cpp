// Cpp file for implementing Context Menu functions

#include "StaticLibLR8.h"

/* Functions Prototypes  */
void OutputMenuText(int, int);
void Theme(int, int);
void Author(int, int);
void Task1(int, int);
void Task2(int, int);
void Exit(int, int);
void Line();

/* Main Function */
int OutputContextMenu() {
  setlocale(LC_ALL, "");
  // Ncurses Initialization
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  // Creating the interactive menu
  int Status = 1, EnterFlag = 0, ch = 0;
  OutputMenuText(Status, EnterFlag);
  while ((ch = getch()) != ESCAPE) {
    std::this_thread::sleep_for(30ms);
    switch(ch) {
      case DOWN_KEY:
        if (Status < 5) {
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

    OutputMenuText(Status, EnterFlag);
    if ((Status == 5 && EnterFlag) || ((Status == 3 || Status == 4) && EnterFlag == 2)) {
      break;
    }
  }

  if ((Status == 5 && EnterFlag) || ch == ESCAPE) {
    endwin();
    system("clear");
    std::cout << "Вы вышли из программы.\n";
    return 0;
  }
  endwin();
  system("clear");
  return Status - 2;
}

/* Bodies of functions */
void OutputMenuText(int Status, int EnterFlag) {
  clear();
  printw("Выберите нужную опцию:\n");
  Theme(Status, EnterFlag);
  Author(Status, EnterFlag);
  Task1(Status, EnterFlag);
  Task2(Status, EnterFlag);
  Exit(Status, EnterFlag);
}

void Theme(int Status, int EnterFlag) {
  std::string Addition = (Status == 1) ? ">  Тема  <" : "   Тема";
  printw("   %s\n", Addition.c_str());
  if (Status == 1 && EnterFlag) {
    Line();
    printw("\n\t\t\tРабота с файлами и структурами в С++.\n\n");
    Line();
  }
}

void Author(int Status, int EnterFlag) {
  std::string Addition = (Status == 2) ? ">  Автор  <" : "   Автор";
  printw("   %s\n", Addition.c_str());
  if (Status == 2 && EnterFlag) {
    Line();
    printw("\n\t\t\tБуховец Устин Глебович, группа 453501.\n\n");
    Line();
  }
}

void Task1(int Status, int EnterFlag) {
  std::string Addition = (Status == 3) ? ">  Задание 1  <" : "   Задание 1";
  printw(" %s\n", Addition.c_str());
  if (Status == 3 && EnterFlag == 1) {
    Line();
    printw("\n\t     В справочной автовокзала имеется расписание движения автобусов.");
    printw("\n\t     Для каждого рейса указаны его номер, тип автобуса, пункт назначения,");
    printw("\n\t     время отправления и прибытия. Вывести информацию о рейсах, которыми");
    printw("\n\t     можно воспользоваться для прибытия в пункт назначения раньше");
    printw("\n\t     заданного времени (сортировка выбором по убыванию). (Нажмите Enter)\n\n");
    Line();
  }
  if (Status == 3 && EnterFlag == 2) {
    clear();
    printw("\n\t<  Перенаправляем Вас...  >");
    refresh();
    std::this_thread::sleep_for(500ms);
  }
}

void Task2(int Status, int EnterFlag) {
  std::string Addition = (Status == 4) ? ">  Задание 2  <" : "   Задание 2";
  printw(" %s\n", Addition.c_str());
  if (Status == 4 && EnterFlag == 1) {
    Line();
    printw("\n\t     У администратора железнодорожных касс хранится информация о");
    printw("\n\t     свободных местах в поездах дальнего следования на ближайшую неделю");
    printw("\n\t     в следующем виде: дата выезда, пункт назначения, время отправления,");
    printw("\n\t     число свободных мест. Оргкомитет международной конференции обращается");
    printw("\n\t     к администратору с просьбой зарезервировать m мест до города N на k-й");
    printw("\n\t     день недели с временем отправления поезда не позднее t часов вечера.");
    printw("\n\t     Вывести время отправления или сообщение о невозможности выполнить заказ");
    printw("\n\t     в полном объеме. (Нажмите Enter)\n\n");
    Line();
  }
  if (Status == 4 && EnterFlag == 2) {
    clear();
    printw("\n\t<  Перенаправляем Вас...  >");
    refresh();
    std::this_thread::sleep_for(500ms);
  }
}

void Exit(int Status, int EnterFlag) {
  std::string Addition = (Status == 5) ? ">  Выход  <" : "   Выход";
  printw("   %s\n", Addition.c_str());
  if (Status == 5 && EnterFlag) {
    clear();
    printw("\n\t   <  Завершение работы...  >");
    refresh();
    std::this_thread::sleep_for(500ms);
  }
}

void Line() {
  printw("------------------------------------------------------------------------------------------\n");
}
