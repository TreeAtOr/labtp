#ifndef KEEPER_H
#define KEEPER_H

#include "../Ship/Sailboat.h"
#include "../Ship/Speedboat.h"
#include "../Ship/Submarine.h"

class Keeper {
private:
    Ship **arrayOfShips;
    Ship **additionalArray = nullptr;
    int counterOfObjectsInAdditionalArray = 0;
    int capacity;
    int counterOfItems = 0;

    void resizeOfArray();

    void freeAdditionalMemory();

public:
    Keeper();

    Keeper(int initialCapacity);

    ~Keeper();

    void addNewItem(Ship *newItem);

    void deleteItem();

    void writeToFile(const std::string &nameOfFile) const;

    void readFromFile(const std::string &nameOfFile);

    void displayData() const;

    void editData(int number);

    int getGounterOfItems() const;
};

bool endsWith(std::string const &value, std::string const &ending);

#endif //KEEPER_H
