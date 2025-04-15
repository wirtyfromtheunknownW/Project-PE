#pragma once
#include <iostream>
#include <string>
#include <fstream>  

class UserGroup {
private:
    std::string name;
    float discountPercent;

public:
    UserGroup();
    UserGroup(std::string n, float d);

    void setName(std::string);
    void setDiscountPercent(float);
    std::string getName() const;
    float getDiscountPercent() const;

    friend std::ostream& operator<<(std::ostream&, const UserGroup&);

    void saveToFile(std::ofstream&) const;
    static UserGroup loadFromFile(std::ifstream&);

};
