#include <Task2.h>

int size2 = 0;

void WriteToFile2(Train*& trains) {
  std::ofstream outFile(filename);
  if (outFile) {
    for (int i = 0; i < size2; ++i) {
      outFile << trains[i].Date << '|' << trains[i].Time << '|' << trains[i].Destination << '|' << trains[i].number.Places << std::endl;
    }
    outFile.close();
  }
  else {
    system("clear");
    std::cout << "Ошибка открытия файла" << std::endl;
  }
}

void ReadFromFile2(Train*& trains) {
  std::ifstream inFile(filename);
  if (inFile) {
    std::string line;
    while (std::getline(inFile, line)) {
      ++size2;
    }
    inFile.clear();
    inFile.seekg(0);
    trains = new Train[size2];
    for (int i = 0; i < size2; ++i) {
      std::getline(inFile, line);
      int pos1 = line.find('|'), pos2 = line.find('|', pos1 + 1), pos3 = line.find('|', pos2 + 1);
      trains[i].Date = line.substr(0, pos1);
      trains[i].Time = line.substr(pos1 + 1, pos2 - pos1 - 1);
      trains[i].Destination = line.substr(pos2 + 1, pos3 - pos2 - 1);
      trains[i].number.Places = std::stoi(line.substr(pos3 + 1));
    }
    inFile.close();
  }
  else {
    system("clear");
    std::cout << "Ошибка открытия файла";
  }
}

void ResizingArray(Train*& trains) {
  Train* NewArray = new Train[++size2];
  for (int i = 0; i < size2 - 1; ++i) {
    NewArray[i] = trains[i];
  }

  delete[] trains;
  trains = NewArray;
}
