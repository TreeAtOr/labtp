#include <windows.h>
#include "menu/MenuOfProgram.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MenuOfProgram* menu = new MenuOfProgram;
    menu->startProgram();

    return 0;
}

