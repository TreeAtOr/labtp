#include "List.h"

void List::addElementToBegin(Train *train) {
    auto newELement = new Element();
    newELement->train = train;

    if (isEmpty()) {
        last = newELement;
    } else {
        newELement->next = first;
        first->prev = newELement;
    }

    first = newELement;
    ++size;
    std::cout << "Поезд добавлен в начало списка, всего поездов: " << size << "\n\n";
}

void List::addElementToEnd(Train *train) {
    auto newElement = new Element();
    newElement->train = train;

    if (isEmpty()) {
        first = newElement;
    } else {
        newElement->prev = last;
        last->next = newElement;
    }
    last = newElement;
    ++size;
    std::cout << "Поезд добавлен в конец списка, всего поездов: " << size << "\n\n";
}

void List::displayList() {
    if (size == 0) {
        throw std::runtime_error("Нет поездов в списке!\n");
    }

    bubbleSort();
    Element *temp = first;
    int counterOfRoutes = 1;
    while (temp) {
        std::cout << counterOfRoutes++ << ") ";
        std::cout << *(temp->train);
        temp = temp->next;
    }
}

List::List() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

List::~List() {
    Element *temp;

    while (first) {
        temp = first->next;
        delete first;
        first = temp;
    }
}

bool List::isEmpty() const {
    return size == 0;
}

void List::deleteElementFromBegin() {
    if (isEmpty()) {
        throw std::runtime_error("Нет поездов в списке!\n");
    }

    Element *newFirstElement = first->next;
    if (size != 1) {
        newFirstElement->prev = nullptr;
    }

    std::cout << "Поезд удален из начала списка!\n\n";
    delete first;
    first = newFirstElement;
    --size;
}

void List::deleteElementFromEnd() {
    if (isEmpty()) {
        throw std::runtime_error("Нет поездов в списке!\n");
    }

    Element *prevElementBeforeLast = last->prev;
    if (size != 1) {
        prevElementBeforeLast->next = nullptr;
    }

    std::cout << "Поезд удален из конца списка!\n\n";
    delete last;
    last = prevElementBeforeLast;
    --size;
}

void List::deleteElementByIndex(int index) {
    if (isEmpty()) {
        throw std::runtime_error("Нет поездов в списке!\n");
    }

    if (isIndexIncorrect(index)) {
        throw std::runtime_error("Введен некорректный индекс!\n");
    }

    if (index == 0) {
        deleteElementFromBegin();
        return;
    }

    if (index == size - 1) {
        deleteElementFromEnd();
        return;
    }

    Element *searchedElement = searchingForElementByIndex(index);

    Element *prevElement = searchedElement->prev;
    Element *nextElement = searchedElement->next;
    prevElement->next = nextElement;
    nextElement->prev = prevElement;
    delete searchedElement;

    std::cout << "Поезд по индексу " << index + 1 << " удален!\n\n";
    --size;
}

void List::editElementByIndex(int index) {
    if (isIndexIncorrect(index)) {
        throw std::runtime_error("Введен некорректный индекс!\n");
    }

    Element *searchedElement;

    if (index == 0) searchedElement = first;
    else if (index == size - 1) searchedElement = last;
    else searchedElement = searchingForElementByIndex(index);

    while (true) {
        system("cls");
        std::cout << *(searchedElement->train);
        std::cout << "Какую информацию о поезде вы хотите изменить?\n"
                  << "1) Название пункта назначения\n"
                  << "2) Номер поезда\n"
                  << "3) Время отправления\n";

        int answer = checkingAccuracyOfTheInput(1, 3);
        if (answer == 1) {
            std::cout << "\n--Введите новое название пункта назначения--\n";
            std::string destination = input<std::string>();
            searchedElement->train->setDestination(destination);
        } else if (answer == 2) {
            std::cout << "\n--Введите новый номер поезда--\n";
            int numberOfTheTrain = input<int>();
            searchedElement->train->setTrainNumber(numberOfTheTrain);
        } else {
            std::cout << "\n--Введите новое время отправления--\n"
                      << "Часы(от 0 до 23):\n";
            int hours = checkingAccuracyOfTheInput(0, 23);
            searchedElement->train->setHours(hours);
            std::cout << "Минуты(от 0 до 59):\n";
            int minutes = checkingAccuracyOfTheInput(0, 59);
            searchedElement->train->setMinutes(minutes);
        }
        std::cout << "Информация о поезде обновлена!\n";
        std::cout << "Желаете ли изменить еще какую-то информацию о данном поезде?(1 - да, 2 - нет)\n";
        int answer1 = checkingAccuracyOfTheInput(1, 2);
        if (answer1 == 2) break;
    }
}

Element *List::searchingForElementByIndex(int index) const {
    Element *searchedElement = first; // кладем указатель на первый элемент для прохода по всему списку
    for (int i = 0; i < index; i++) { // поиск элемента с заданным индексом
        searchedElement = searchedElement->next;
    } // searchedElement - узел, который располагается в данный момент по заданному индексу
    return searchedElement;
}

bool List::isIndexIncorrect(int index) const {
    return (index >= size || index < 0);
}

int List::getSize() const {
    return size;
}

void List::swapTrains(Train *train1, Train *train2) {
    //сохранение всех значений первого поезда
    auto destination = train1->getDestination();
    auto numberOfTrain = train1->getTrainNumber();
    auto hours = train1->getHours();
    auto minutes = train1->getMinutes();

    //установка значений второго поезда для первого поезда
    train1->setDestination(train2->getDestination());
    train1->setTrainNumber(train2->getTrainNumber());
    train1->setHours(train2->getHours());
    train1->setMinutes(train2->getMinutes());

    //установка значений первого поезда для второго поезда
    train2->setDestination(destination);
    train2->setTrainNumber(numberOfTrain);
    train2->setHours(hours);
    train2->setMinutes(minutes);
}

void List::bubbleSort() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            auto element1 = searchingForElementByIndex(j)->train;
            auto element2 = searchingForElementByIndex(j + 1)->train;
            if (element1->getDestination() > element2->getDestination()) {
                swapTrains(element1, element2);
            }
        }
    }
}

void List::displayTrainsDepartingAfterACertainTime(int hours, int minutes) {
    if (isEmpty()) {
        throw std::runtime_error("Нет поездов в списке!\n");
    }

    bool flag = true; // флаг, что поезда после заданного времени отправления не были обнаружены
    Element *searchedElement = first;
    int counter = 1; // счетчик найденных поездов

    for (int i = 0; i < size; i++) {
        Train *currentTrain = searchedElement->train;
        if (compareTime(currentTrain->getHours(),currentTrain->getMinutes(),
                        hours, minutes)) {
            if (flag) {
                std::cout << "Поезда, отправляющиеся после ";
                if (hours < 10) std::cout << "0";
                std::cout << hours << ":";

                if (minutes < 10) std::cout << "0";
                std::cout << minutes << "\n\n";
            }

            std::cout << counter++ << ") " << *currentTrain;
            flag = false;
        }
        searchedElement = searchedElement->next;
    }

    if (flag) {
        std::cout << "Поезда, отправляющиеся после " << hours << ":" << minutes << ", не были найдены в списке!\n";
    }
}

bool compareTime(int hours1, int minutes1, int hours2, int minutes2) {
    if (hours1 > hours2) {
        return true;
    }

    if (hours1 == hours2) {
        if (minutes1 > minutes2) {
            return true;
        }
    }

    return false;
}

