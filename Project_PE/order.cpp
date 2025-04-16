#include "order.h"

Order::Order() : user(), meal(), finalPrice(0.0f) {}

Order::Order(User u, Meal m)
    : user(u), meal(m), finalPrice(m.getPriceForGroup(u.getGroup())) {
}

User Order::getUser() const { return user; }
Meal Order::getMeal() const { return meal; }
float Order::getFinalPrice() const { return finalPrice; }

void Order::saveToFile(std::ofstream& out) const {
    out << user.getUsername() << '\n'
        << meal.getName() << '\n'
        << finalPrice << '\n';
}

Order Order::loadFromFile(std::ifstream& in, const std::vector<User>& users, const std::vector<Meal>& meals) {
    std::string username, mealName;
    float price;
    std::getline(in, username);
    std::getline(in, mealName);
    in >> price;
    in.ignore();

    User u;
    Meal m;

    for (const auto& usr : users)
        if (usr.getUsername() == username)
            u = usr;

    for (const auto& ml : meals)
        if (ml.getName() == mealName)
            m = ml;

    Order o(u, m);
    return o;
}

std::ostream& operator<<(std::ostream& out, const Order& o) {
    out << "Поръчка: " << o.user.getUsername()
        << " -> " << o.meal.getName()
        << " = " << o.finalPrice << " лв.";
    return out;
}
