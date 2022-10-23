#include "Speedboat.h"

Speedboat::Speedboat() {
    std::cout << "Вызван конструктор без парматеров для класса Катер!\n";
    purpose = "";
    housingMaterial = "";
    drivingQualities = "";
    speed = 0.0;
    maxCountOfPeople = 0;
}

Speedboat::Speedboat(const std::string &purpose, const std::string &housingMaterial,
                     const std::string &drivingQualities, double speed, int countOfPeople) {
    std::cout << "Вызван конструктор c параметрами для класса Катер!\n";
    this->purpose = purpose;
    this->housingMaterial = housingMaterial;
    this->drivingQualities = drivingQualities;
    this->speed = speed;
    this->maxCountOfPeople = countOfPeople;
}

Speedboat::Speedboat(const Speedboat &speedboat2) {
    std::cout << "Вызван конструктор копирования для класса Катер!\n";
    purpose = speedboat2.purpose;
    housingMaterial = speedboat2.housingMaterial;
    drivingQualities = speedboat2.drivingQualities;
    speed = speedboat2.speed;
    maxCountOfPeople = speedboat2.maxCountOfPeople;
}

Speedboat::~Speedboat() {
    std::cout << "Вызван деструктор для класса Катер!\n";
}

Speedboat *Speedboat::clone() const {
    return new Speedboat(*this);
}

void Speedboat::displayData() const {
    std::cout << "---Катер---\n";
    std::cout << "Назначение: " << purpose << "\nМатериал корпуса: " << housingMaterial
              << "\nХодовые качества: " << drivingQualities << "\nСкорость: " << speed << " узла/ов"
              << "\nКоличество людей, который могут находиться на борту: " << maxCountOfPeople << "\n\n";
}

const std::string &Speedboat::getPurpose() const {
    return purpose;
}

void Speedboat::setPurpose(const std::string &purpose) {
    this->purpose = purpose;
}

const std::string &Speedboat::getHousingMaterial() const {
    return housingMaterial;
}

void Speedboat::setHousingMaterial(const std::string &housingMaterial) {
    this->housingMaterial = housingMaterial;
}

const std::string &Speedboat::getDrivingQualities() const {
    return drivingQualities;
}

void Speedboat::setDrivingQualities(const std::string &drivingQualities) {
    this->drivingQualities = drivingQualities;
}

double Speedboat::getSpeed() const {
    return speed;
}

void Speedboat::setSpeed(double speed) {
    this->speed = speed;
}

int Speedboat::getCountOfPeople() const {
    return maxCountOfPeople;
}

void Speedboat::setCountOfPeople(int countOfPeople) {
    this->maxCountOfPeople = countOfPeople;
}

void Speedboat::writeToFile(std::fstream &file) const {
    //В файл пишется перед полями объекта каждого класса его уникальный идентификатор для удобства
    // восстановления состояния программы при следующих запусках:
    // подводная лодка -> 1, парусник -> 2, катер -> 3
    file << NameOfClass::SpeedboatId << "\n";

    file << purpose << "\n" << housingMaterial << "\n" << drivingQualities << "\n" << speed << "\n"
         << maxCountOfPeople << "\n";
}

void Speedboat::readFromFile(std::fstream &file) {
    purpose = safeInputFromFile<std::string>(file);
    housingMaterial = safeInputFromFile<std::string>(file);
    drivingQualities = safeInputFromFile<std::string>(file);
    speed = safeInputFromFile<double>(file);
    maxCountOfPeople = safeInputFromFile<int>(file);
}

void Speedboat::editData() {
    while (true) {
        system("cls");
        displayData();
        std::cout << "Какую информацию о катере вы хотите изменить?\n";
        std::cout << "1) Назначение\n"
                  << "2) Материал корпуса\n"
                  << "3) Ходовые качества\n"
                  << "4) Скорость\n"
                  << "5) Количество людей, которые могут находится на борту\n";

        int answer = checkingAccuracyOfTheInput(1, 5);
        switch (answer) {
            case 1: {
                std::cout << "Введите назначение катера\n";
                std::string purposeOfSpeedboat = input<std::string>();
                setPurpose(purposeOfSpeedboat);
                break;
            }
            case 2: {
                std::cout << "Введите материал корпуса катера\n";
                std::string housingMaterialOfSpeedboat = input<std::string>();
                setHousingMaterial(housingMaterialOfSpeedboat);
                break;
            }
            case 3: {
                std::cout << "Введите ходовые качества катера\n";
                std::string drivingQualitiesOfSpeedboat = input<std::string>();
                setDrivingQualities(drivingQualitiesOfSpeedboat);
                break;
            }
            case 4: {
                std::cout << "Введите скорость катера в узлах\n";
                double speedOfSpeedboat = input<double>();
                setSpeed(speedOfSpeedboat);
                break;
            }
            case 5: {
                std::cout << "Введите количество людей, которые могут находится на борту катера\n";
                int countOfPeople = input<int>();
                setCountOfPeople(countOfPeople);
                break;
            }
        }
        std::cout << "Информация о катере обновлена!\n";
        std::cout << "\nЖелаете ли изменить еще какую-то информацию?(1 - да, 2 - нет)\n";
        int answer1 = checkingAccuracyOfTheInput(1, 2);
        if (answer1 == 2) break;
    }
}

std::istream &operator>>(std::istream &is, Speedboat &speedboat) {
    std::cout << "\nНазначение\n";
    speedboat.setPurpose(input<std::string>());

    std::cout << "\nМатериал корпуса\n";
    speedboat.setHousingMaterial(input<std::string>());

    std::cout << "\nХодовые качества\n";
    speedboat.setDrivingQualities(input<std::string>());

    std::cout << "\nСкорость в узлах\n";
    speedboat.setSpeed(input<double>());

    std::cout << "\nКоличество людей, которые могут находится на борту\n";
    speedboat.setCountOfPeople(input<int>());

    return is;
}
