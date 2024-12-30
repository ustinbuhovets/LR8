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
/*  Reliant  */
void CorrectDateInput(std::string&);

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
      // FindingTrains();
      break;
    case 3:
      AddingTrains();
      break;
    case 4:
      // RemovingTrains();
      break;
    case 5:
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
    std::cout << std::setw(3) << i+1 << ".  " << std::left << std::setw(7) << trains[i].Date << "|  " << std::setw(15) << trains[i].Destination << "|  " << std::setw(5) << trains[i].number.Places << std::endl;
  }
  Line2();
  std::cout << " Вернуться - 0: ";
  std::getchar();
  std::cin.ignore(80, '\n');
}

//

void AddingTrains() {
  system("clear");
  std::cout << "  Меню добавления рейса: \n";
  Line2();
  ResizingArray(trains);
  std::cout << "  Введите дату нового рейса (XX.YY.ZZZZ): ";
  CorrectDateInput(trains[size2-1].Date);
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