#include <Task2.h>

/*  Functions Prototypes  */
void Line2() {
  std::cout << "---------------------------------------------------------------------------------\n";
}
void CallingMenus(int);
void WatchingTrains();
void FindingTrains();
void AddingTrains();
void RemovingTrains();
void RedactingTrains();
/*  Reliant  */
void CorrectDateInput(std::string&);
void CorrectTimeInput(std::string&);
void CorrectIntInput(int&);


void OutputTerminal() {
  int Number;
  do {
    system("clear");
    std::cout << "  Выберите интересующую вас опцию:\n";
    std::this_thread::sleep_for(50ms);
    Line2();
    std::cout << " 1. Просмотреть рейсы\n";
    std::this_thread::sleep_for(50ms);
    std::cout << " 2. Найти рейс\n";
    std::this_thread::sleep_for(50ms);
    std::cout << " 3. Добавить рейс\n";
    std::this_thread::sleep_for(50ms);
    std::cout << " 4. Удалить рейс\n";
    std::this_thread::sleep_for(50ms);
    std::cout << " 5. Изменить рейс\n";
    std::this_thread::sleep_for(50ms);
    std::cout << " 6. Выйти\n";
    std::this_thread::sleep_for(50ms);
    Line2();
    std::this_thread::sleep_for(50ms);
    std::cout << " Введите номер интересующей вас опции: ";
    do {
      Number = std::getchar() - 48;
      std::cin.ignore(255, '\n');
      if (!(Number >= 1 && Number <= 6)) {
        std::cout << " Некорректный ввод. Попробуйте еще раз: ";
      }
    } while (!(Number >= 1 && Number <= 6));

    if (Number == 6) {
      system("clear");
      std::cout << "Вы вышли из программы.\n";
      return;
    }
    CallingMenus(Number);
    Number = 0;
  } while (Number != 6);
}

void CallingMenus(int Status) {
  switch(Status) {
    case 1:
      WatchingTrains();
      break;
    case 2:
      FindingTrains();
      break;
    case 3:
      AddingTrains();
      break;
    case 4:
      RemovingTrains();
      break;
    case 5:
      RedactingTrains();
      break;
    default:
      break;
  }
} 

void WatchingTrains() {
  system("clear");
  std::cout << "  Доступные рейсы:\n";
  Line2();
  for (int i = 0; i < size2; ++i) {
    std::cout << std::right << std::setw(3) << i+1 << ".  " << std::left << std::setw(7) << trains[i].Date << "|  " << std::setw(5) << trains[i].Time << "  |  " << trains[i].Destination << "  |  " << std::setw(5) << trains[i].number.Places << std::endl;
  }
  Line2();
  std::cout << " Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
}

void FindingTrains() {
  system("clear");
  std::string date, destination;
  int places;
  std::cout << "  Интерактивное окно поиска рейса:\n";
  Line2();
  std::cout << "  Введите дату, на которую желаете найти рейс: ";
  CorrectDateInput(date);
  std::cout << "  Введите пункт назначения, в который желаете поехать: ";
  std::cin >> destination; 
  std::cout << "  Введите количество мест, необходимое для Вашей поездки: ";
  CorrectIntInput(places);
  Line2();

  bool flag = false;
  for (int i = 0; i < size2; ++i) {
    if (trains[i].Date == date && trains[i].Destination == destination && trains[i].number.Places <= places) {
      if (!flag) {
        std::cout << "  Возможно, вам подойдут следующие рейсы:\n";
      }
      std::cout << std::right << std::setw(3) << i+1 << ".  " << std::left << std::setw(7) << trains[i].Date << "|  " << std::setw(5) << trains[i].Time << "  |  " << trains[i].Destination << "  |  " << std::setw(5) << trains[i].number.Places << std::endl;
      flag = true;
    }
  }
  if (!flag) {
    std::cout << "  Увы, у нас нет подходящих для Вас рейсов.\n";
  }

  std::cout << "\n  Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
}

void AddingTrains() {
  system("clear");
  std::cout << "  Меню добавления рейса: \n";
  Line2();
  ResizingArray(trains);
  std::cout << "  Введите дату нового рейса (XX.YY.ZZZZ): ";
  CorrectDateInput(trains[size2-1].Date);
  std::cout << "  Введите время отправления нового рейса (HH:MM): ";
  CorrectTimeInput(trains[size2-1].Time);
  std::cout << "  Введите пункт назначения рейса: ";
  std::cin >> trains[size2-1].Destination;
  std::cout << "  Введите количество свободных мест на рейс: ";
  CorrectIntInput(trains[size2-1].number.Places);
  Line2();
  std::cout << "  Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
  WriteToFile2(trains);
}

void RemovingTrains() {
  system("clear");
  std::cout << "  Меню удаления рейса: \n";
  std::string date, destination;
  Line2();
  std::cout << "  Введите дату рейса, который желаете удалить: ";
  CorrectDateInput(date);
  std::cout << "  Введите пункт назначения рейса, который желаете удалить: ";
  std::cin >> destination;
  Line2();

  int index = -1;
  for (int i = 0; i < size2; ++i) {
    if (trains[i].Date == date && trains[i].Destination == destination) {
      index = i;
      break;
    }
  }
  if (index >= 0) {
    for (int i = index; i < size2 - 1; ++i) {
      trains[i] = trains[i+1];
    }
    --size2;
    WriteToFile2(trains);
  }
  else {
    std::cout << "  Подобный рейс не найден.\n";
  }
  std::cout << "\n  Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
}

void RedactingTrains() {
  system("clear");
  std::cout << "  Меню редактирования рейса: \n";
  std::string date, destination;
  Line2();
  std::cout << "  Введите дату рейса, который желаете редактировать: ";
  CorrectDateInput(date);
  std::cout << "  Введите пункт назначения рейса, который желаете редактировать: ";
  std::cin >> destination;
  Line2();

  bool flag = false;
  for (int i = 0; i < size2; ++i) {
    if (trains[i].Date == date && trains[i].Destination == destination) {
      flag = true;
      std::cout << "  Введите новую дату: ";
      CorrectDateInput(trains[i].Date);
      std::cout << "  Введите новое время: ";
      CorrectTimeInput(trains[i].Time);
      std::cout << "  Введите новый пункт назначения: ";
      std::cin >> trains[i].Destination;
      std::cout << "  Введите новое количество свободных мест: ";
      CorrectIntInput(trains[i].number.Places);
      WriteToFile2(trains);
      break;
    }
  }
  if (!flag) {
    std::cout << "  Подобный рейс не найден.\n";
  }

  Line2();
  std::cout << "  Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
}
/*  Reliant  */
void CorrectDateInput(std::string& Date) {
  do {
    std::cin >> Date;
    std::cin.ignore(80, '\n');
    if (Date.length() > 10 || Date[2] != '.' || Date[5] != '.' || !isdigit(Date[0]) || !isdigit(Date[1]) || !isdigit(Date[3]) || !isdigit(Date[4]) || !isdigit(Date[6]) || !isdigit(Date[7])|| !isdigit(Date[8]) || !isdigit(Date[9])) {
      std::cout << "  Некорректный ввод. Попробуйте еще раз (XX.YY.ZZZZ): ";
    }
  } while (Date.length() > 10 || Date[2] != '.' || Date[5] != '.' || !isdigit(Date[0]) || !isdigit(Date[1]) || !isdigit(Date[3]) || !isdigit(Date[4]) || !isdigit(Date[6]) || !isdigit(Date[7])|| !isdigit(Date[8]) || !isdigit(Date[9]));
}

void CorrectTimeInput(std::string& Time) {
  while (!(std::cin >> Time) || std::cin.peek() != '\n' || !isdigit(Time[0]) || !isdigit(Time[1]) || Time[2] != ':' || !isdigit(Time[3]) || !isdigit(Time[4]) || Time.length() > 5) {
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::cout << "  Некорректный формат времени. Попробуйте еще раз: ";
  }
}

void CorrectIntInput(int& N) {
  while (!(std::cin >> N) || std::cin.peek() != '\n' || N < 0) {
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::cout << "  Некорректный ввод. Повторите попытку: ";
  }
}
