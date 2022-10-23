#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <fstream>
#include "../../../lib/safeInputFromFile.h"
#include "../../../lib/checkingAccuracyOfTheInput.h"
#include "NameOfClass.h"

class Ship {
protected:
    Ship();

public:
    virtual void writeToFile(std::fstream &file) const = 0;

    virtual void readFromFile(std::fstream &file) = 0;

    virtual void editData() = 0;

    virtual void displayData() const = 0;

    virtual Ship *clone() const = 0;

    virtual ~Ship();
};


#endif //SHIP_H
