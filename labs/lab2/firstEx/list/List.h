#ifndef LIST_H
#define LIST_H
#include "Element.h"

class List {
private:
    Element *first;
    Element *last;
    int size;

    void bubbleSort();

    void swapTrains(Train *train1, Train *train2);

    Element *searchingForElementByIndex(int index) const;

    bool isIndexIncorrect(int index) const;

public:
    List();

    ~List();

    int getSize() const;

    void editElementByIndex(int index);

    void deleteElementFromBegin();

    void deleteElementFromEnd();

    void deleteElementByIndex(int index);

    void addElementToEnd(Train *train);

    void addElementToBegin(Train *train);

    bool isEmpty() const;

    void displayList();

    void displayTrainsDepartingAfterACertainTime(int hours, int minutes);
};

bool compareTime(int hours1, int minutes1, int hours2, int minutes2);

#endif //LIST_H
