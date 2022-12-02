#include "Submarine.h"

void Submarine::displayData() const {
    std::cout << "---Подводная лодка---\n";
    std::cout << "Экипаж: " << crew << "\nВооружение: " << arms << "\nДлина: " << length << " метра/ов"
              << "\nШирина: " << width << " метра/ов" << "\nВремя непрерывного пребывания под водой: "
              << timeOfContinuousStayUnderWater << " минут/ы"
              << "\nМаксимальная подводная скорость: " << maximumSpeed << " узла/ов\n\n";
}

Submarine::Submarine() {
    std::cout << "Вызван конструктор без парматеров для класса Подводная лодка!\n";
    length = 0.0;
    width = 0.0;
    crew = "";
    timeOfContinuousStayUnderWater = 0;
    maximumSpeed = 0.0;
    arms = "";
}

Submarine::Submarine(const std::string &crew, const std::string &arms, double length, double width,
                     int timeOfContinuousStayUnderWater, double maximumSpeed) {
    std::cout << "Вызван конструктор с параметрами для класса Подводная лодка!\n";
    this->length = length;
    this->width = width;
    this->crew = crew;
    this->timeOfContinuousStayUnderWater = timeOfContinuousStayUnderWater;
    this->maximumSpeed = maximumSpeed;
    this->arms = arms;
}

Submarine::Submarine(const Submarine &ship2) {
    std::cout << "Вызван конструктор копирования для класса Подводная лодка!\n";
    length = ship2.length;
    width = ship2.width;
    crew = ship2.crew;
    timeOfContinuousStayUnderWater = ship2.timeOfContinuousStayUnderWater;
    maximumSpeed = ship2.maximumSpeed;
    arms = ship2.arms;
}

Ship *Submarine::clone() const {
    return new Submarine(*this);
}

Submarine::~Submarine() {
    std::cout << "Вызван деструктор для класса Подводная лодка!\n";
}

double Submarine::getLength() const {
    return length;
}

void Submarine::setLength(double length) {
    this->length = length;
}

double Submarine::getWidth() const {
    return width;
}

void Submarine::setWidth(double width) {
    this->width = width;
}

const std::string &Submarine::getCrew() const {
    return crew;
}

void Submarine::setCrew(const std::string &crew) {
    this->crew = crew;
}

int Submarine::getTimeOfContinuousStayUnderWater() const {
    return timeOfContinuousStayUnderWater;
}

void Submarine::setTimeOfContinuousStayUnderWater(int timeOfContinuousStayUnderWater) {
    this->timeOfContinuousStayUnderWater = timeOfContinuousStayUnderWater;
}

double Submarine::getMaximumSpeed() const {
    return maximumSpeed;
}

void Submarine::setMaximumSpeed(double maximumSpeed) {
    this->maximumSpeed = maximumSpeed;
}

const std::string &Submarine::getArms() const {
    return arms;
}

void Submarine::setArms(const std::string &arms) {
    this->arms = arms;
}

void Submarine::writeToFile(std::fstream &file) const {
    //В файл пишется перед полями объекта каждого класса его уникальный идентификатор для удобства
    // восстановления состояния программы при следующих запусках:
    // подводная лодка -> 1, парусник -> 2, катер -> 3
    file << NameOfClass::SubmarineId << "\n";

    file << crew << "\n" << arms << "\n" << length << "\n" << width << "\n"
         << timeOfContinuousStayUnderWater << "\n" << maximumSpeed << "\n";
}

void Submarine::readFromFile(std::fstream &file) {
    crew = safeInputFromFile<std::string>(file);
    arms = safeInputFromFile<std::string>(file);
    length = safeInputFromFile<double>(file);
    width = safeInputFromFile<double>(file);
    timeOfContinuousStayUnderWater = safeInputFromFile<int>(file);
    maximumSpeed = safeInputFromFile<double>(file);
}

void Submarine::editData() {
    while (true) {
        system("clear");
        displayData();
        std::cout << "Какую информацию о подводной лодке вы хотите изменить?\n";
        std::cout << "1) Экипаж\n"
                  << "2) Вооружение\n"
                  << "3) Длина\n"
                  << "4) Ширина\n"
                  << "5) Время непрерывного пребывания под водой\n"
                  << "6) Максимальная подводная скорость\n";

        int answer = checkingAccuracyOfTheInput(1, 6);
        switch (answer) {
            case 1: {
                std::cout << "Введите экипаж подлодки\n";
                std::string crewOfSubmarine = input<std::string>();
                setCrew(crewOfSubmarine);
                break;
            }
            case 2: {
                std::cout << "Введите вооружение подлодки\n";
                std::string armsOfSubmarine = input<std::string>();
                setArms(armsOfSubmarine);
                break;
            }
            case 3: {
                std::cout << "Введите длину подлодки в метрах\n";
                double lengthOfSubmarine = input<double>();
                setLength(lengthOfSubmarine);
                break;
            }
            case 4: {
                std::cout << "Введите ширину подлодки в метрах\n";
                double widthOfSubmarine = input<double>();
                setWidth(widthOfSubmarine);
                break;
            }
            case 5: {
                std::cout << "Введите время непрерывного пребывания под водой на подлодке в минутах\n";
                int timeUnderWater = input<int>();
                setTimeOfContinuousStayUnderWater(timeUnderWater);
                break;
            }
            case 6: {
                std::cout << "Введите максимальная подводная скорость\n";
                double maxSpeed = input<double>();
                setMaximumSpeed(maxSpeed);
                break;
            }
        }
        std::cout << "Информация о подлодке обновлена!\n";
        std::cout << "\nЖелаете ли изменить еще какую-то информацию?(1 - да, 2 - нет)\n";
        int answer1 = checkingAccuracyOfTheInput(1, 2);
        if (answer1 == 2) break;
    }
}

std::istream &operator>>(std::istream &is, Submarine &submarine) {
    std::cout << "\nЭкипаж\n";
    submarine.setCrew(input<std::string>());

    std::cout << "\nВооружение\n";
    submarine.setArms(input<std::string>());

    std::cout << "\nДлина в метрах\n";
    submarine.setLength(input<double>());

    std::cout << "\nШирина в метрах\n";
    submarine.setWidth(input<double>());

    std::cout << "\nВремя непрерывного пребывания под водой в минутах\n";
    submarine.setTimeOfContinuousStayUnderWater(input<int>());

    std::cout << "\nМаксимальная подводная скорость в узлах\n";
    submarine.setMaximumSpeed(input<double>());

    return is;
}