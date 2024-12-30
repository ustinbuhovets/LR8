#include <Task1.h>

int size = 0;

/*  Functions for implementing task  */
// Basic functions
void ErrorMessage() {
  std::cerr << "Ошибка открытия файла" << std::endl;
}

/*  Working with the files  */
void WriteToFile(Bus*& buses) {
  std::ofstream outFile(filename, std::ios::binary);
  if (outFile) {
    outFile.write((char*)(buses), size * sizeof(Bus));
    outFile.close();
  }
  else {
    ErrorMessage();
  }
}

void ReadFromFile(Bus*& buses) {
  std::ifstream inFile(filename, std::ios::binary);
  if (inFile) {
    inFile.seekg(0, std::ios::end);
    size = inFile.tellg() / sizeof(Bus);
    inFile.seekg(0, std::ios::beg);
    buses = (Bus*)malloc(size * sizeof(Bus));
    inFile.read((char*)(buses), size * sizeof(Bus));
    inFile.close();
  }
  else {
    ErrorMessage();
  }
}

/*  Functions for menus  */
// Outputting Info
void OutputBusesInfo(Bus*& buses) {
  for (int i = 0; i < size; ++i) {
    wchar_t buffer[256];
    swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
    printw("|%3d. %ls|\n", i+1, buffer);
  }
}

// Finding Flight
bool CorrectTimeInput(wchar_t* SearchTime) {
  if (!isdigit(SearchTime[0]) || SearchTime[0] > '2') {
    return false;
  }
  if (!isdigit(SearchTime[1]) || (SearchTime[1] > '4' && SearchTime[0] == '2')) {
    return false;
  }
  if (SearchTime[2] != ':') {
    return false;
  }
  if (!isdigit(SearchTime[3]) || SearchTime[3] > '5') {
    return false;
  }
  if (!isdigit(SearchTime[4])) {
    return false;
  }
  return true;
}

void FindFlightNumber(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n");
  Line1();
  printw("  Введите номер автобуса, который вы желаете найти: ");
  refresh();
  char SearchNumber[5];
  getnstr(SearchNumber, 4);
  printw("  Найденные рейсы:\n");
  Line1();
  int index = 1;
  for (int i = 0; i < size; ++i) {
    if (strstr(buses[i].Number, SearchNumber)) {
      wchar_t buffer[256];
      swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
      printw("|%3d. %ls|\n", index, buffer);
      ++index;
    }
  }
  if (index == 1) {
    printw("| Увы, мы не нашли таких рейсов. Попробуйте ввести другое значение         |\n");
  }
  Line1(); 
  printw("\n  / Заново (Enter)\n");
  printw("  / Вернуться (Esc)\n");
}

void FindFlightType(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n");
  Line1();
  printw("  Введите тип автобуса, который вы желаете найти: ");
  refresh();
  wchar_t SearchType[80];
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(SearchType), 79);
  printw("  Найденные рейсы:\n");
  Line1();
  int index = 1;
  for (int i = 0; i < size; ++i) {
    if (wcsstr(buses[i].Type, SearchType)) {
      wchar_t buffer[256];
      swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
      printw("|%3d. %ls|\n", index, buffer);
      ++index;
    }
  }
  if (index == 1) {
    printw("| Увы, мы не нашли таких рейсов. Попробуйте ввести другое значение         |\n");
  }
  Line1(); 
  printw("\n  / Заново (Enter)\n");
  printw("  / Вернуться (Esc)\n");
}

void FindFlightDestination(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n");
  Line1();
  printw("  Введите пункт назначения автобуса, который вы желаете найти: ");
  refresh();
  wchar_t SearchDestination[80];
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(SearchDestination), 79);
  printw("  Найденные рейсы:\n");
  Line1();
  int index = 1;
  for (int i = 0; i < size; ++i) {
    if (wcsstr(buses[i].Destination, SearchDestination)) {
      wchar_t buffer[256];
      swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
      printw("|%3d. %ls|\n", index, buffer);
      ++index;
    }
  }
  if (index == 1) {
    printw("| Увы, мы не нашли таких рейсов. Попробуйте ввести другое значение         |\n");
  }
  Line1(); 
  printw("\n  / Заново (Enter)\n");
  printw("  / Вернуться (Esc)\n");
}

void FindFlightDepartationTime(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n");
  Line1();
  printw("  Введите время выезда автобуса, который вы желаете найти: ");
  refresh();
  wchar_t SearchDepartationTime[6];
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(SearchDepartationTime), 5);
  printw("  Найденные рейсы:\n");
  Line1();
  int index = 1;
  for (int i = 0; i < size; ++i) {
    if (wcscmp(buses[i].DepartationTime, SearchDepartationTime) <= 0 && CorrectTimeInput(SearchDepartationTime)) {
      wchar_t buffer[256];
      swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
      printw("|%3d. %ls|\n", index, buffer);
      ++index;
    }
  }
  if (index == 1) {
    printw("| Увы, мы не нашли таких рейсов. Попробуйте ввести другое значение (HH:MM) |\n");
  }
  Line1(); 
  printw("\n  / Заново (Enter)\n");
  printw("  / Вернуться (Esc)\n");
}

void FindFlightArrivingTime(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n");
  Line1();
  printw("  Введите время прибытия автобуса, который вы желаете найти: ");
  refresh();
  wchar_t SearchArrivingTime[6];
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(SearchArrivingTime), 5);
  printw("  Найденные рейсы:\n");
  Line1();
  int index = 1;
  for (int i = 0; i < size; ++i) {
    if (wcscmp(buses[i].ArrivingTime, SearchArrivingTime) <= 0 && CorrectTimeInput(SearchArrivingTime)) {
      wchar_t buffer[256];
      swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
      printw("|%3d. %ls|\n", index, buffer);
      ++index;
    }
  }
  if (index == 1) {
    printw("| Увы, мы не нашли таких рейсов. Попробуйте ввести другое значение (HH:MM) |\n");
  }
  Line1(); 
  printw("\n  / Заново (Enter)\n");
  printw("  / Вернуться (Esc)\n");
}

void FindFlight(Bus*& buses, int Status) {
  switch(Status) {
    case 1:     // Number
      FindFlightNumber(buses);
      break;
    case 2:     // Type
      FindFlightType(buses);
      break;
    case 3:     // Destination
      FindFlightDestination(buses);
      break;
    case 4:     // Departation
      FindFlightDepartationTime(buses);
      break;
    case 5:     // Arriving
      FindFlightArrivingTime(buses);
      break;
    default:
      break;
  }
}

// Adding Bus
void AddBus(Bus*& buses) {
  buses = (Bus*)realloc(buses, (++size) * sizeof(Bus));
  printw("Введите номер автобуса (до 4х символов): ");
  getnstr(buses[size-1].Number, 4);
  printw("Введите тип автобуса: ");
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].Type), 79);
  printw("Введите пункт назначения автобуса: ");
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].Destination), 79);
  printw("Введите время отправления автобуса с автовокзала (HH:MM): ");
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].DepartationTime), 5);
  while (!CorrectTimeInput(buses[size-1].DepartationTime)) {
    printw("Некорректный ввод. Попробуйте еще раз (HH:MM): ");
    wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].DepartationTime), 5);
  }
  printw("Введите время прибытия автобуса в пункт назначения (HH:MM): ");
  wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].ArrivingTime), 5);
  while (!CorrectTimeInput(buses[size-1].ArrivingTime)) {
    printw("Некорректный ввод. Попробуйте еще раз (HH:MM): ");
    wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[size-1].ArrivingTime), 5);
  }
  WriteToFile(buses);
}

// Removing Bus
void ChooseRemovingBusText(Bus*& buses, int Status) {
  clear();
  printw("  Выберите рейс, информацию о котором желаете удалить:\n");
  Line1();
  for (int i = 0; i < size; ++i) {
    wchar_t buffer[256];
    swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
    if (Status == i + 1) {
      printw("| [ %3d. %ls ] |\n", i+1, buffer);
    }
    else {
      printw("|   %3d. %ls   |\n", i+1, buffer);
    }
  }
  Line1();
  printw("\n");
  if (Status == size + 1) {
    printw(" > Вернуться <\n");
  }
  else {
    printw("   Вернуться\n");
  }
}

void RemoveBus(Bus*& buses) {
  int NewStatus = 1, ch, NewEnterFlag = 0;
  ChooseRemovingBusText(buses, NewStatus);
  while ((ch = getch()) != ESCAPE) {
    switch (ch) {
      case DOWN_KEY:
        if (NewStatus <= size) {
          ++NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case UP_KEY:
        if (NewStatus > 1) {
          --NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case ENTER:
        if (NewEnterFlag < 1) {
          ++NewEnterFlag;
        }
        break;
    }

    if (NewEnterFlag == 1) {
      if (NewStatus == size + 1) {
        break;
      }
      else {
        int index = NewStatus - 1;
        for (int i = index; i < size - 1; ++i) {
          buses[i] = buses[i + 1];
        }
        --size;
        WriteToFile(buses);
        NewStatus = 1;
        NewEnterFlag = 0;
      }
    }
    ChooseRemovingBusText(buses, NewStatus);
  }
}

// Redacting Bus
void ChooseRedactingBusText(Bus*& buses, int Status) {
  clear();
  printw("  Выберите рейс, информацию о котором желаете изменить:\n");
  Line1();
  for (int i = 0; i < size; ++i) {
    wchar_t buffer[256];
    swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
    if (Status == i + 1) {
      printw("| [ %3d. %ls ] |\n", i+1, buffer);
    }
    else {
      printw("|   %3d. %ls   |\n", i+1, buffer);
    }
  }
  Line1();
  printw("\n");
  if (Status == size + 1) {
    printw(" > Вернуться <\n");
  }
  else {
    printw("   Вернуться\n");
  }
}

void RedactBus(Bus*& buses) {
  int NewStatus = 1, NewEnterFlag = 0, ch;
  ChooseRedactingBusText(buses, NewStatus);
  while ((ch = getch()) != ESCAPE) {
    switch (ch) {
      case DOWN_KEY:
        if (NewStatus <= size) {
          ++NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case UP_KEY:
        if (NewStatus > 1) {
          --NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case ENTER:
        if (NewEnterFlag < 1) {
          ++NewEnterFlag;
        }
        break;
    }

    if (NewEnterFlag == 1) {
      if (NewStatus == size + 1) {
        break;
      }
      else {
        clear();
        printw("Меню редактирования рейса:\n");
        int index = NewStatus - 1;
        wchar_t buffer[256];
        swprintf(buffer, sizeof(buffer), L"%5s | %-20ls| %-20ls| %-7ls| %-7ls", buses[index].Number, buses[index].Type, buses[index].Destination, buses[index].DepartationTime, buses[index].ArrivingTime);
        Line1();
        printw("|%ls|\n", buffer);
        Line1();
        printw("Введите номер автобуса (до 4х символов): ");
        getnstr(buses[index].Number, 4);
        printw("Введите тип автобуса: ");
        wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].Type), 79);
        printw("Введите пункт назначения автобуса: ");
        wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].Destination), 79);
        printw("Введите время отправления автобуса с автовокзала (HH:MM): ");
        wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].DepartationTime), 5);
        while (!CorrectTimeInput(buses[size-1].DepartationTime)) {
          printw("Некорректный ввод. Попробуйте еще раз (HH:MM): ");
          wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].DepartationTime), 5);
        }
        printw("Введите время прибытия автобуса в пункт назначения (HH:MM): ");
        wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].ArrivingTime), 5);
        while (!CorrectTimeInput(buses[size-1].ArrivingTime)) {
          printw("Некорректный ввод. Попробуйте еще раз (HH:MM): ");
          wgetn_wstr(stdscr, reinterpret_cast<wint_t*>(buses[index].ArrivingTime), 5);
        }
        WriteToFile(buses);
      }
    }
    ChooseRedactingBusText(buses, NewStatus);
  }
}

// Sorting Buses
void SortBusesByNumber(Bus*& buses) {
  int index;
  for (int i = 0; i < size; ++i) {
    index = i;
    for (int j = i+1; j < size; ++j) {
      if (strcmp(buses[j].Number, buses[index].Number) > 0) {
        index = j;
      }
    }
    std::swap(buses[i], buses[index]);
  }
}

void SortBusesByDepartationTime(Bus*& buses) {
  int index;
  for (int i = 0; i < size; ++i) {
    index = i;
    for (int j = i+1; j < size; ++j) {
      if (wcscmp(buses[j].DepartationTime, buses[index].DepartationTime) > 0) {
        index = j;
      }
    }
    std::swap(buses[i], buses[index]);
  }
}

void SortBusesByArrivingTime(Bus*& buses) {
  int index;
  for (int i = 0; i < size; ++i) {
    index = i;
    for (int j = i+1; j < size; ++j) {
      if (wcscmp(buses[j].ArrivingTime, buses[index].ArrivingTime) > 0) {
        index = j;
      }
    }
    std::swap(buses[i], buses[index]);
  }
}

void SortBusesText(int NewStatus) {
  clear();
  printw("Выберите критерий, по которому желаете отсортировать список автобусов:\n");
  std::string Addition = (NewStatus == 1) ? ">  Номер  <" : "   Номер";
  printw("1. %s\n", Addition.c_str());
  Addition = (NewStatus == 2) ? ">  Время выезда  <" : "   Время выезда";
  printw("2. %s\n", Addition.c_str());
  Addition = (NewStatus == 3) ? ">  Время прибытия  <" : "   Время прибытия";
  printw("3. %s\n", Addition.c_str());
  Addition = (NewStatus == 4) ? "> Вернуться <" : "  Вернуться";
  printw("\n %s\n", Addition.c_str());
}

void SortBusesFunction(Bus*& buses) {
  int NewStatus = 1, NewEnterFlag = 0, ch = 0;
  SortBusesText(NewStatus);
  while ((ch = getch()) != ESCAPE) {
    switch (ch) {
      case DOWN_KEY:
        if (NewStatus < 4) {
          ++NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case UP_KEY:
        if (NewStatus > 1) {
          --NewStatus;
          NewEnterFlag = 0;
        }
        break;
      case ENTER:
        if (NewEnterFlag < 1) {
          ++NewEnterFlag;
        }
        break;
    }

    if (NewEnterFlag == 1) {
      if (NewStatus == 1) {
        SortBusesByNumber(buses);
        break;
      }
      if (NewStatus == 2) {
        SortBusesByDepartationTime(buses);
        break;
      }
      if (NewStatus == 3) {
        SortBusesByArrivingTime(buses);
        break;
      }
      if (NewStatus == 4) {
        break;
      }
    }
    SortBusesText(NewStatus);
  }
}