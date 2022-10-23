#include "Menu.h"

using namespace libtp;

void Menu::startProgram() const {
  while (true) {
    try {
      system("clear");
      std::cout << "1) Добавить новый корабль\n"
                << "2) Удалить последний добавленный корабль\n"
                << "3) Изменить поля конкретного корабля\n"
                << "4) Вывести информацию о всех кораблях на экран\n"
                << "5) Сохранить текущие корабли в файл\n"
                << "6) Загрузить информацию о кораблях из файла\n"
                << "7) Выход из программы\n";
      int reply = input<int>();
      system("clear");
      switch (reply) {
      case 1: {
        std::cout << "Выберите объект какого типа вы хотели бы добавить:\n"
                  << "1) Подводная лодка\n2) Парусник\n3) Катер\n";
        int answer = checkingAccuracyOfTheInput(1, 3);
        if (answer == 1) {
          auto submarine = new Submarine;
          std::cin >> *submarine;
          keeper->addNewItem(submarine);
        } else if (answer == 2) {
          auto sailboat = new Sailboat;
          std::cin >> *sailboat;
          keeper->addNewItem(sailboat);
        } else {
          auto speedboat = new Speedboat;
          std::cin >> *speedboat;
          keeper->addNewItem(speedboat);
        }
        break;
      }
      case 2: {
        isCounterOfItemsEqualsZero();
        keeper->deleteItem();
        break;
      }
      case 3: {
        isCounterOfItemsEqualsZero();
        std::cout << "---Изменение информации об объекте---\n"
                  << "Информацию о каком объекте вы хотите изменить?\n\n";
        keeper->displayData();

        std::cout << "\nВведите индекс для изменения информации о корабле, "
                     "всего элементов "
                  << keeper->getGounterOfItems()
                  << ".\nИндекс должен быть от 1 до "
                  << keeper->getGounterOfItems() << "\n";

        int index = checkingAccuracyOfTheInput(1, keeper->getGounterOfItems());
        keeper->editData(index - 1);
        break;
      }
      case 4: {
        isCounterOfItemsEqualsZero();
        keeper->displayData();
        break;
      }
      case 5: {
        isCounterOfItemsEqualsZero();
        std::cout << "---Запись объектов в файл---\n";
        std::cout << "Введите имя файла в формате(имя_файла.txt)\n";
        std::string nameOfFile = input<std::string>();
        keeper->writeToFile(nameOfFile);
        break;
      }
      case 6: {
        std::cout << "---Чтение информации из файла---\n";
        std::cout << "Имя файла в формате(имя_файла.txt)\n";
        std::string name_of_file = input<std::string>();

        keeper->readFromFile(name_of_file);
        break;
      }
      case 7:
        std::cout << "Выход из программы..\n";
        system("pause");
        exit(1);
      default:
        std::cout << "Введена неверная цифра! Повторите попытку.\n";
      }
    } catch (exception &e) {
      std::cout << "\n" << e.getError();
      if (e.isCriticalError()) {
        std::cout << "Программа сброшена до начального состояния!\n\n";
      }
    }
    system("pause");
  }
}

void Menu::isCounterOfItemsEqualsZero() const {
  if (keeper->getGounterOfItems() == 0) {
    throw exception("В программе пока отсутствуют корабли! Добавьте их через "
                    "консоль или загрузите "
                    "из файла\n",
                    false);
  }
}

Menu::Menu() { keeper = new Keeper(); }

Menu::~Menu() { delete keeper; }
