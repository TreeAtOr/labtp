#ifndef MENUOFPROGRAM_H
#define MENUOFPROGRAM_H
#include "../firstEx/list/List.h"
#include "../secondEx/TextAnalysis.h"

class MenuOfProgram {
private:
    List *listOfTrains;

    void firstEx();

    void secondEx();

public:
    MenuOfProgram();

    ~MenuOfProgram();

    void startProgram();
};


#endif //MENUOFPROGRAM_H
