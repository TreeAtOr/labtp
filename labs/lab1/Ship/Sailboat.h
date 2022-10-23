#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"

class Sailboat : public Ship {
private:
    std::string type;
    std::string title;
    std::string crew;
    double bodyLength;
    bool isMilitary;
    double speed;

public:
    Sailboat();

    Sailboat(const std::string &type, const std::string &title, const std::string &crew, double bodyLength,
             bool isMilitary, double speed);

    Sailboat(const Sailboat &sailboat2);

    ~Sailboat() override;

    void displayData() const override;

    friend std::istream &operator>>(std::istream &is, Sailboat &sailboat);

    Ship *clone() const override;

    void writeToFile(std::fstream &file) const override;

    void readFromFile(std::fstream &file) override;

    void editData() override;

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    bool getIsMilitary() const;

    void setIsMilitary(bool isMilitary);

    double getBodyLength() const;

    void setBodyLength(double bodyLength);

    double getSpeed() const;

    void setSpeed(double speed);

    const std::string &getCrew() const;

    void setCrew(const std::string &crew);
};


#endif //SAILBOAT_H
