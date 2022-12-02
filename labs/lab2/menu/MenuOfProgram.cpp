#include "MenuOfProgram.h"

MenuOfProgram::MenuOfProgram() {
    listOfTrains = new List();
}

MenuOfProgram::~MenuOfProgram() {
    delete listOfTrains;
}

void MenuOfProgram::startProgram() {
    std::cout << "Выберите с каким заданием хотите работать:\n"
              << "1) Первое задание\n"
              << "2) Второе задание\n"
              << "3) Выход\n";
    int answer = checkingAccuracyOfTheInput(1, 3);

    if (answer == 1) firstEx();
    else if (answer == 2) secondEx();
    else {
        std::cout << "Выход из программы..\n";
        system("pause");
        exit(1);
    }
}

void MenuOfProgram::firstEx() {
    while (true) {
        system("cls");
        std::cout << "1) Добавить поезд в список\n"
                  << "2) Изменить информацию о поезде\n"
                  << "3) Удалить поезд из списка\n"
                  << "4) Показать список поездов\n"
                  << "5) Вывести список поездов, которые отправляются после определенного времени\n"
                  << "6) Перейти ко второму заданию\n"
                  << "7) Выйти из программы\n";
        int answer = input<int>();
        system("cls");
        switch (answer) {
            case 1: {
                std::cout << "---Добавление поезда---\n";
                auto newTrain = new Train;
                std::cin >> *newTrain;

                listOfTrains->addElementToBegin(newTrain);
                break;
            }
            case 2: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "Поезда пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Изменение информации о поезде---\n"
                          << "Информацию о каком поезде вы хотите изменить?\n\n";
                listOfTrains->displayList();

                std::cout << "\nВведите индекс для изменения информации о поезде, всего элементов "
                          << listOfTrains->getSize() << ".\nИндекс должен быть от 1 до " << listOfTrains->getSize()
                          << "\n";
                int index = checkingAccuracyOfTheInput(1, listOfTrains->getSize());
                listOfTrains->editElementByIndex(index - 1);
                break;
            }
            case 3: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "Поезда пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Удаление поезда из списка---\n"
                          << "Какой поезд вы хотите удалить из списка?\n\n";
                listOfTrains->displayList();
                std::cout << "\nВведите индекс поезда, который хотите удалить, всего элементов "
                          << listOfTrains->getSize() << ".\nИндекс должен быть от 1 до " << listOfTrains->getSize()
                          << "\n";
                int index = checkingAccuracyOfTheInput(1, listOfTrains->getSize());
                listOfTrains->deleteElementByIndex(index - 1);
                break;
            }
            case 4: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "Поезда пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Все текущие поезда в программе---\n\n";
                listOfTrains->displayList();
                break;
            }
            case 5: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "Поезда пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Вывод поездов которые отправляются после определенного времени---\n\n";
                std::cout << "Введите время\n"
                          << "Часы(от 0 до 23)\n";
                int hours = checkingAccuracyOfTheInput(0, 23);
                std::cout << "Минуты(от 0 до 59)\n";
                int minutes = checkingAccuracyOfTheInput(0, 59);
                listOfTrains->displayTrainsDepartingAfterACertainTime(hours, minutes);
                break;
            }
            case 6:
                secondEx();
            case 7: {
                std::cout << "Выход из программы..\n";
                system("pause");
                exit(1);
            }
            default: {
                std::cout << "Введена неверная цифра, повторите попытку!\n";
            }
        }

        system("pause");
    }
}

void MenuOfProgram::secondEx() {
    while (true) {
        try {
            system("cls");
            std::cout << "Программа находит слова, состоящие не более, чем из 4 букв\n";
            std::cout << "1) Считывать информацию из файла\n"
                      << "2) Выход из программы\n";
            int answer = checkingAccuracyOfTheInput(1, 2);

            if (answer == 1) {
                std::cout << "Введите имя файла в формате(имя_файла.txt)\n";
                std::string nameOfFile = input<std::string>();
                TextAnalysis::readFromFile(nameOfFile);
            } else {
                std::cout << "Выход из программы..\n";
                system("pause");
                exit(1);
            }
        } catch (std::runtime_error &e) {
            std::cout << "\n" << e.what() << "\n";
        }

        system("pause");
    }
}