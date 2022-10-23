#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship {
private:
    std::string crew;
    std::string arms;
    double length;
    double width;
    int timeOfContinuousStayUnderWater;
    double maximumSpeed;
public:
    Submarine();

    Submarine(const std::string &crew, const std::string &arms, double length, double width,
              int timeOfContinuousStayUnderWater, double maximumSpeed);

    Submarine(const Submarine& ship2);

    void displayData() const override;

    Ship *clone() const override;

    ~Submarine() override;

    friend std::istream& operator>> (std::istream& is, Submarine &submarine);

    void editData() override;

    void writeToFile(std::fstream &file) const override;

    void readFromFile(std::fstream &file) override;

    double getLength() const;

    void setLength(double length);

    double getWidth() const;

    void setWidth(double width);

    const std::string &getCrew() const;

    void setCrew(const std::string &crew);

    int getTimeOfContinuousStayUnderWater() const;

    void setTimeOfContinuousStayUnderWater(int timeOfContinuousStayUnderWater);

    double getMaximumSpeed() const;

    void setMaximumSpeed(double maximumSpeed);

    const std::string &getArms() const;

    void setArms(const std::string &arms);

};


#endif //SUBMARINE_H
