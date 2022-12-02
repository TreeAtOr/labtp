#include "MenuOfProgram.h"

MenuOfProgram::MenuOfProgram() {
    listOfTrains = new List();
}

MenuOfProgram::~MenuOfProgram() {
    delete listOfTrains;
}

void MenuOfProgram::startProgram() {
    std::cout << "�������� � ����� �������� ������ ��������:\n"
              << "1) ������ �������\n"
              << "2) ������ �������\n"
              << "3) �����\n";
    int answer = checkingAccuracyOfTheInput(1, 3);

    if (answer == 1) firstEx();
    else if (answer == 2) secondEx();
    else {
        std::cout << "����� �� ���������..\n";
        system("pause");
        exit(1);
    }
}

void MenuOfProgram::firstEx() {
    while (true) {
        system("cls");
        std::cout << "1) �������� ����� � ������\n"
                  << "2) �������� ���������� � ������\n"
                  << "3) ������� ����� �� ������\n"
                  << "4) �������� ������ �������\n"
                  << "5) ������� ������ �������, ������� ������������ ����� ������������� �������\n"
                  << "6) ������� �� ������� �������\n"
                  << "7) ����� �� ���������\n";
        int answer = input<int>();
        system("cls");
        switch (answer) {
            case 1: {
                std::cout << "---���������� ������---\n";
                auto newTrain = new Train;
                std::cin >> *newTrain;

                listOfTrains->addElementToBegin(newTrain);
                break;
            }
            case 2: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "������ ���� �� ��������� � ���������!\n";
                    break;
                }
                std::cout << "---��������� ���������� � ������---\n"
                          << "���������� � ����� ������ �� ������ ��������?\n\n";
                listOfTrains->displayList();

                std::cout << "\n������� ������ ��� ��������� ���������� � ������, ����� ��������� "
                          << listOfTrains->getSize() << ".\n������ ������ ���� �� 1 �� " << listOfTrains->getSize()
                          << "\n";
                int index = checkingAccuracyOfTheInput(1, listOfTrains->getSize());
                listOfTrains->editElementByIndex(index - 1);
                break;
            }
            case 3: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "������ ���� �� ��������� � ���������!\n";
                    break;
                }
                std::cout << "---�������� ������ �� ������---\n"
                          << "����� ����� �� ������ ������� �� ������?\n\n";
                listOfTrains->displayList();
                std::cout << "\n������� ������ ������, ������� ������ �������, ����� ��������� "
                          << listOfTrains->getSize() << ".\n������ ������ ���� �� 1 �� " << listOfTrains->getSize()
                          << "\n";
                int index = checkingAccuracyOfTheInput(1, listOfTrains->getSize());
                listOfTrains->deleteElementByIndex(index - 1);
                break;
            }
            case 4: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "������ ���� �� ��������� � ���������!\n";
                    break;
                }
                std::cout << "---��� ������� ������ � ���������---\n\n";
                listOfTrains->displayList();
                break;
            }
            case 5: {
                if (listOfTrains->getSize() == 0) {
                    std::cout << "������ ���� �� ��������� � ���������!\n";
                    break;
                }
                std::cout << "---����� ������� ������� ������������ ����� ������������� �������---\n\n";
                std::cout << "������� �����\n"
                          << "����(�� 0 �� 23)\n";
                int hours = checkingAccuracyOfTheInput(0, 23);
                std::cout << "������(�� 0 �� 59)\n";
                int minutes = checkingAccuracyOfTheInput(0, 59);
                listOfTrains->displayTrainsDepartingAfterACertainTime(hours, minutes);
                break;
            }
            case 6:
                secondEx();
            case 7: {
                std::cout << "����� �� ���������..\n";
                system("pause");
                exit(1);
            }
            default: {
                std::cout << "������� �������� �����, ��������� �������!\n";
            }
        }

        system("pause");
    }
}

void MenuOfProgram::secondEx() {
    while (true) {
        try {
            system("cls");
            std::cout << "��������� ������� �����, ��������� �� �����, ��� �� 4 ����\n";
            std::cout << "1) ��������� ���������� �� �����\n"
                      << "2) ����� �� ���������\n";
            int answer = checkingAccuracyOfTheInput(1, 2);

            if (answer == 1) {
                std::cout << "������� ��� ����� � �������(���_�����.txt)\n";
                std::string nameOfFile = input<std::string>();
                TextAnalysis::readFromFile(nameOfFile);
            } else {
                std::cout << "����� �� ���������..\n";
                system("pause");
                exit(1);
            }
        } catch (std::runtime_error &e) {
            std::cout << "\n" << e.what() << "\n";
        }

        system("pause");
    }
}