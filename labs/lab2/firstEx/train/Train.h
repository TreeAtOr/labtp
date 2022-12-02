#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>
#include "../../../../lib/checkingAccuracyOfTheInput.h"
using namespace libtp;

class Train {
private:
    std::string destination;
    int trainNumber;
    int hours;
    int minutes;
public:
    Train();

    Train(const std::string& destination, int trainNumber, int hours, int minutes);

    Train(const Train& train2);

    ~Train();

    friend std::ostream &operator<<(std::ostream &os, const Train &train);

    friend std::istream& operator>> (std::istream& is, Train &train);

    const std::string &getDestination() const;

    void setDestination(const std::string &destination);

    int getTrainNumber() const;

    void setTrainNumber(int trainNumber);

    int getHours() const;

    void setHours(int hours);

    int getMinutes() const;

    void setMinutes(int minutes);
};


#endif //TRAIN_H
