#pragma once
#include "User.h"
#include "Meal.h"
#include <string>
#include <fstream>

class Order {
private:
    User user;
    Meal meal;
    float finalPrice;

public:
    Order();
    Order(User u, Meal m);

    User getUser() const;
    Meal getMeal() const;
    float getFinalPrice() const;

    void saveToFile(std::ofstream&) const;
    static Order loadFromFile(std::ifstream&, const std::vector<User>&, const std::vector<Meal>&);

    friend std::ostream& operator<<(std::ostream&, const Order&);
};
