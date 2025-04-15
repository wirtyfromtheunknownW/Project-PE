#pragma once
#include <iostream>
#include <string>
#include "UserGroup.h"
#include <fstream>  

class Meal {
private:
    std::string name;
    float basePrice;

public:
    Meal();
    Meal(std::string, float);

    void setName(std::string);
    void setBasePrice(float);
    std::string getName() const;
    float getBasePrice() const;

    float getPriceForGroup(const UserGroup&) const;
    void saveToFile(std::ofstream&) const;
    static Meal loadFromFile(std::ifstream&);

    friend std::ostream& operator<<(std::ostream&, const Meal&);
};
