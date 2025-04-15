#include "Meal.h"
#include <fstream>

Meal::Meal() : name(""), basePrice(0.0f) {}
Meal::Meal(std::string n, float p) : name(n), basePrice(p) {}

void Meal::setName(std::string n) { name = n; }
void Meal::setBasePrice(float p) { basePrice = p; }
std::string Meal::getName() const { return name; }
float Meal::getBasePrice() const { return basePrice; }

float Meal::getPriceForGroup(const UserGroup& g) const {
    return basePrice * (1 - g.getDiscountPercent() / 100);
}

std::ostream& operator<<(std::ostream& out, const Meal& m) {
    out << "Ястие: " << m.name << ", Базова цена: " << m.basePrice << " лв.";
    return out;
}


void Meal::saveToFile(std::ofstream& out) const {
    out << name << '\n' << basePrice << '\n';
}

Meal Meal::loadFromFile(std::ifstream& in) {
    std::string name;
    float price;
    std::getline(in, name);
    in >> price;
    in.ignore();
    return Meal(name, price);
}

