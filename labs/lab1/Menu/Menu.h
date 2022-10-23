#ifndef MENU_H
#define MENU_H

#include "../Keeper/Keeper.h"

class Menu {
private:
    Keeper *keeper;

    void isCounterOfItemsEqualsZero() const;

public:
    Menu();

    ~Menu();

    void startProgram() const;
};


#endif //MENU_H
