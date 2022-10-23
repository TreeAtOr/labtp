#include "Sailboat.h"

void Sailboat::displayData() const {
    std::cout << "---Парусник---\n";
    std::cout << "Тип парусника: " << type << "\nНазвание: " << title << "\nЭкипаж: " << crew
              << "\nДлина корпуса: " << bodyLength << " метра/ов" << "\nВоенный: ";

    if (isMilitary) std::cout << "да";
    else std::cout << "нет";

    std::cout << "\nСкорость перемещения: " << speed << " узла/ов\n\n";
}

Ship *Sailboat::clone() const {
    return new Sailboat(*this);
}

Sailboat::~Sailboat() {
    std::cout << "Вызван деструктор для класса Парусник!\n";
}

Sailboat::Sailboat(const std::string &type, const std::string &title, const std::string &crew, double bodyLength,
                   bool isMilitary, double speed) {
    std::cout << "Вызван конструктор с параметрами для класса Парусник!\n";
    this->type = type;
    this->title = title;
    this->isMilitary = isMilitary;
    this->bodyLength = bodyLength;
    this->speed = speed;
    this->crew = crew;
}

Sailboat::Sailboat() {
    std::cout << "Вызван конструктор без параметров для класса Парусник!\n";
    type = "";
    title = "";
    isMilitary = false;
    bodyLength = 0.0;
    speed = 0.0;
    crew = "";
}

Sailboat::Sailboat(const Sailboat &sailboat2) {
    std::cout << "Вызван конструктор копирования для класса Парусник!\n";
    type = sailboat2.type;
    title = sailboat2.title;
    isMilitary = sailboat2.isMilitary;
    bodyLength = sailboat2.bodyLength;
    speed = sailboat2.speed;
    crew = sailboat2.crew;
}

const std::string &Sailboat::getType() const {
    return type;
}

void Sailboat::setType(const std::string &type) {
    this->type = type;
}

const std::string &Sailboat::getTitle() const {
    return title;
}

void Sailboat::setTitle(const std::string &title) {
    this->title = title;
}

bool Sailboat::getIsMilitary() const {
    return isMilitary;
}

void Sailboat::setIsMilitary(bool isMilitary) {
    this->isMilitary = isMilitary;
}

double Sailboat::getBodyLength() const {
    return bodyLength;
}

void Sailboat::setBodyLength(double bodyLength) {
    this->bodyLength = bodyLength;
}

double Sailboat::getSpeed() const {
    return speed;
}

void Sailboat::setSpeed(double speed) {
    this->speed = speed;
}

const std::string &Sailboat::getCrew() const {
    return crew;
}

void Sailboat::setCrew(const std::string &crew) {
    this->crew = crew;
}

void Sailboat::writeToFile(std::fstream &file) const {
    //В файл пишется перед полями объекта каждого класса его уникальный идентификатор для удобства
    // восстановления состояния программы при следующих запусках:
    // подводная лодка -> 1, парусник -> 2, катер -> 3
    file << NameOfClass::SailboatId << "\n";

    file << type << "\n" << title << "\n" << crew << "\n"
         << bodyLength << "\n" << isMilitary << "\n" << speed << "\n";
}

void Sailboat::readFromFile(std::fstream &file) {
    type = safeInputFromFile<std::string>(file);
    title = safeInputFromFile<std::string>(file);
    crew = safeInputFromFile<std::string>(file);
    bodyLength = safeInputFromFile<double>(file);
    isMilitary = safeInputFromFile<int>(file);
    speed = safeInputFromFile<double>(file);
}

void Sailboat::editData() {
    while (true) {
        system("cls");
        displayData();
        std::cout << "Какую информацию о паруснике вы хотите изменить?\n";
        std::cout << "1) Тип парусника\n"
                  << "2) Название\n"
                  << "3) Экипаж\n"
                  << "4) Длина корпуса\n"
                  << "5) Военный или мирный\n"
                  << "6) Скорость перемещения\n";

        int answer = checkingAccuracyOfTheInput(1, 6);
        switch (answer) {
            case 1: {
                std::cout << "Введите тип парусника\n";
                std::string typeOfSailboat = input<std::string>();
                setType(typeOfSailboat);
                break;
            }
            case 2: {
                std::cout << "Введите название парусника\n";
                std::string titleOfSailboat = input<std::string>();
                setTitle(titleOfSailboat);
                break;
            }
            case 3: {
                std::cout << "Введите экипаж парусника\n";
                std::string crewOfSailboat = input<std::string>();
                setCrew(crewOfSailboat);
                break;
            }
            case 4: {
                std::cout << "Введите длину корпуса парусника в метрах\n";
                double lengthOfSailboat = input<double>();
                setBodyLength(lengthOfSailboat);
                break;
            }
            case 5: {
                std::cout << "Военный или мирный парусник?(1 - военный, 0 - мирный)\n";
                bool isMilitarySailboat = checkingAccuracyOfTheInput(0, 1);
                setIsMilitary(isMilitarySailboat);
                break;
            }
            case 6: {
                std::cout << "Введите скорость перемещения парусника в узлах\n";
                double speedOfSailboat = input<double>();
                setSpeed(speedOfSailboat);
                break;
            }
        }
        std::cout << "Информация о паруснике обновлена!\n";
        std::cout << "\nЖелаете ли изменить еще какую-то информацию?(1 - да, 2 - нет)\n";
        int answer1 = checkingAccuracyOfTheInput(1, 2);
        if (answer1 == 2) break;
    }
}

std::istream &operator>>(std::istream &is, Sailboat &sailboat) {
    std::cout << "\nТип парусника\n";
    sailboat.setType(input<std::string>());

    std::cout << "\nНазвание парусника\n";
    sailboat.setTitle(input<std::string>());

    std::cout << "\nЭкипаж парусника\n";
    sailboat.setCrew(input<std::string>());

    std::cout << "\nДлина корпуса в метрах\n";
    sailboat.setBodyLength(input<double>());

    std::cout << "\nВоенный или мирный парусник?(1 - военный, 0 - мирный)\n";
    sailboat.setIsMilitary(checkingAccuracyOfTheInput(0, 1));

    std::cout << "\nСкорость перемещения в узлах\n";
    sailboat.setSpeed(input<double>());

    return is;
}
