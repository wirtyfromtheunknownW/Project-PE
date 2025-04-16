#include "UserGroup.h"
#include <fstream>

UserGroup::UserGroup() : name(""), discountPercent(0.0f) {}
UserGroup::UserGroup(std::string n, float d) : name(n), discountPercent(d) {}

void UserGroup::setName(std::string n) { name = n; }
void UserGroup::setDiscountPercent(float d) { discountPercent = d; }
std::string UserGroup::getName() const { return name; }
float UserGroup::getDiscountPercent() const { return discountPercent; }

std::ostream& operator<<(std::ostream& out, const UserGroup& g) {
    out << "Group: " << g.name << ", Discount: " << g.discountPercent << "%";
    return out;
}


void UserGroup::saveToFile(std::ofstream& out) const {
    out << name << '\n' << discountPercent << '\n';
}

UserGroup UserGroup::loadFromFile(std::ifstream& in) {
    std::string name;
    float discount;
    std::getline(in, name);
    in >> discount;
    in.ignore(); // игнорира нов ред след float
    return UserGroup(name, discount);
}
