#include "Train.h"

const std::string &Train::getDestination() const {
    return destination;
}

void Train::setDestination(const std::string &destination) {
    this->destination = destination;
}

int Train::getTrainNumber() const {
    return trainNumber;
}

void Train::setTrainNumber(int trainNumber) {
    this->trainNumber = trainNumber;
}

Train::Train() {
    std::cout << "������ ����������� ��� ���������� ��� ������ Train\n\n";
    destination = "";
    trainNumber = 0;
    hours = 0;
    minutes = 0;
}

Train::Train(const std::string &destination, int trainNumber, int hours, int minutes) {
    std::cout << "������ ����������� � ����������� ��� ������ Train\n\n";
    this->destination = destination;
    this->trainNumber = trainNumber;
    this->hours = hours;
    this->minutes = minutes;
}

Train::Train(const Train &train2) {
    std::cout << "������ ����������� ����������� ��� ������ Train\n\n";
    destination = train2.destination;
    trainNumber = train2.trainNumber;
    hours = train2.hours;
    minutes = train2.minutes;
}

Train::~Train() {
    std::cout << "������ ���������� ��� ������ Train\n\n";
}

std::istream &operator>>(std::istream &is, Train &train) {
    std::cout << "������� �������� ������ ����������\n";
    train.setDestination(input<std::string>());

    std::cout << "\n������� ����� ������\n";
    train.setTrainNumber(input<int>());

    std::cout << "\n������� ����� ����������� ������\n"
              << "����(�� 0 �� 23)\n";
    train.setHours(checkingAccuracyOfTheInput(0, 23));

    std::cout << "\n������(�� 0 �� 59)\n";
    train.setMinutes(checkingAccuracyOfTheInput(0, 59));

    return is;
}

std::ostream &operator<<(std::ostream &os, const Train &train) {
    std::cout << "����� ����������: " << train.getDestination() << "\n����� ������: " << train.getTrainNumber()
              << "\n����� �����������: ";
    if (train.getHours() < 10) std::cout << "0";
    std::cout << train.getHours() << ":";

    if (train.getMinutes() < 10) std::cout << "0";
    std::cout << train.getMinutes() << "\n\n";

    return os;
}

int Train::getHours() const {
    return hours;
}

void Train::setHours(int hours) {
    this->hours = hours;
}

int Train::getMinutes() const {
    return minutes;
}

void Train::setMinutes(int minutes) {
    this->minutes = minutes;
}
