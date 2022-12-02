#ifndef ELEMENT_H
#define ELEMENT_H
#include "../train/Train.h"

class Element {
public:
    Train* train;
    Element *next;
    Element *prev;

    Element();

    ~Element();
};


#endif //ELEMENT_H