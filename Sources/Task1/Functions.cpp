#include <Task1.h>

int size = 5;

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

void InitializeBuses(Bus*& buses) {
  buses[0] = {"1", L"Пассажирский", L"Гомель", L"11:00", L"15:45"};
  buses[1] = {"52", L"Скоростной", L"Владикавказ", L"02:23", L"17:46"};
  buses[2] = {"1488", L"Двухколесный", L"Атлантида", L"11:11", L"22:22"};
  buses[3] = {"2", L"Экспресс", L"Барановичи", L"12:00", L"14:00"};
  buses[4] = {"3", L"Пассажирский", L"Люксембург", L"9:15", L"9:20"};
  WriteToFile(buses);
}

/*  Functions for menus  */
void OutputBusesInfo(Bus*& buses) {
  for (int i = 0; i < size; ++i) {
    wchar_t buffer[256];
    swprintf(buffer, sizeof(buffer), L"%5d | %-20ls| %-20ls| %-7ls| %-7ls", buses[i].Number, buses[i].Type, buses[i].Destination, buses[i].DepartationTime, buses[i].ArrivingTime);
    printw("|  %d. %ls|\n", i+1, buffer);
  }
}

void FindFlightNumber(Bus*& buses) {
  clear();
  printw("  Поиск рейса:\n-------------------------------------------------------------------------------\n");
  printw("  Введите номер автобуса, который вы желаете найти: ");
  refresh();
  char SearchNumber[5];
  getnstr(SearchNumber, 4);
  
}

void FindFlight(Bus*& buses, int Status) {
  switch(Status) {
    case 1:     // Number
      FindFlightNumber(buses);
      break;
    case 2:     // Type
      break;
    case 3:     // Destination
      break;
    case 4:     // Departation
      break;
    case 5:     // Arriving
      break;
  }
}
