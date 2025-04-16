#include "LoadFile.h"

void LoadFile() {
    std::ifstream inG("groups.txt"), inU("users.txt"), inM("meals.txt");
    if (!inG || !inU || !inM) {
        std::cout << "Error While Opening File.\n";
        return;
    }

    groups.clear();
    users.clear();
    meals.clear();

    while (inG.peek() != EOF)
        groups.push_back(UserGroup::loadFromFile(inG));

    while (inU.peek() != EOF)
        users.push_back(User::loadFromFile(inU, groups));

    while (inM.peek() != EOF)
        meals.push_back(Meal::loadFromFile(inM));

    std::cout << "Data Loaded Successfully.\n";
}