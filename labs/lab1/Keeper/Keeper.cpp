#include "Keeper.h"

Keeper::Keeper() {
    capacity = 10;
    arrayOfShips = new Ship *[capacity];
}

Keeper::Keeper(int initialCapacity) {
    capacity = initialCapacity;
    arrayOfShips = new Ship *[capacity];
}

void Keeper::resizeOfArray() {
    int newSize = capacity + 10;
    auto biggerArray = new Ship *[newSize];

    for (int i = 0; i < counterOfItems; i++) {
        biggerArray[i] = arrayOfShips[i]->clone();
    }

    for (int i = 0; i < counterOfItems; i++) {
        delete arrayOfShips[i];
    }
    delete[] arrayOfShips;

    capacity = newSize;
    arrayOfShips = biggerArray;
    std::cout << "Размер keeper'a увеличен до " << capacity << "\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < counterOfItems; i++) {
        delete arrayOfShips[i];
    }
    delete[] arrayOfShips;

    freeAdditionalMemory();
}

void Keeper::addNewItem(Ship *newItem) {
    if (capacity == counterOfItems) {
        resizeOfArray();
    }

    arrayOfShips[counterOfItems] = newItem;
    counterOfItems++;
    std::cout << "\nЭлемент успешно добавлен в keeper!\n";
}

void Keeper::deleteItem() {
    if (counterOfItems == 0) {
        throw exception("Пока что в программе нет элементов для удаления!\n", false);
    }
    arrayOfShips[counterOfItems - 1]->displayData();
    delete arrayOfShips[counterOfItems - 1];
    std::cout << "Объект успешно удален!\n";
    counterOfItems--;
}

void Keeper::writeToFile(const std::string &nameOfFile) const {
    if (!endsWith(nameOfFile, ".txt")) {
        throw exception("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n",
                          false);
    }

    std::fstream file;
    file.open(nameOfFile, std::ios::out);
    if (!file.is_open()) {
        file.close();
        throw exception("Ошибка при открытие файла!\n", false);
    }

    for (int i = 0; i < counterOfItems; i++) {
        arrayOfShips[i]->writeToFile(file);
    }

    std::cout << "Данные успешно были записаны в файл!\n\n";
    file.close();
}

void Keeper::readFromFile(const std::string &nameOfFile) {

    if (!endsWith(nameOfFile, ".txt")) {
        throw exception("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n",
                          false);
    }

    std::fstream file;
    file.open(nameOfFile, std::ios::in);
    if (!file.is_open()) {
        file.close();
        throw exception("Ошибочное открытие файла!\n", false);
    }

    freeAdditionalMemory();

    const int sizeOfAdditionalArray = 100;
    additionalArray = new Ship *[sizeOfAdditionalArray];

    std::string className;
    while (std::getline(file, className)) {

        if (className == "1") {
            additionalArray[counterOfObjectsInAdditionalArray] = new Submarine;
        } else if (className == "2") {
            additionalArray[counterOfObjectsInAdditionalArray] = new Sailboat;
        } else if (className == "3") {
            additionalArray[counterOfObjectsInAdditionalArray] = new Speedboat;
        } else {
            file.close();
            throw exception("Считывается странный объект из файла, выход!\n", true);
        }

        additionalArray[counterOfObjectsInAdditionalArray++]->readFromFile(file);
    }

    for (int i = 0; i < counterOfObjectsInAdditionalArray; ++i) {
        if (counterOfItems == capacity) {
            resizeOfArray();
        }
        arrayOfShips[counterOfItems++] = additionalArray[i]->clone();
    }

    std::cout << "Данные успешно считаны из файла!\n\n";
    file.close();
}

void Keeper::freeAdditionalMemory() {
    for (int i = 0; i < counterOfObjectsInAdditionalArray; ++i) {
        delete additionalArray[i];
    }
    delete[] additionalArray;
    counterOfObjectsInAdditionalArray = 0;
}

void Keeper::displayData() const {
    if (counterOfItems == 0) {
        throw exception("Пока что элементов в программе нет!\n", false);
    }

    std::cout << "Созданных объектов в программе: " << counterOfItems << "\n";
    for (int i = 0; i < counterOfItems; i++) {
        std::cout << i + 1 << ")";
        arrayOfShips[i]->displayData();
    }
}

void Keeper::editData(int number) {
    arrayOfShips[number]->editData();
    std::cout << "Данные об объекте изменены упешно!\n";
}

int Keeper::getGounterOfItems() const {
    return counterOfItems;
}

bool endsWith(std::string const &value, std::string const &ending) {
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
