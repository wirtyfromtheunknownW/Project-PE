#include <iostream>
#include <vector>
#include "UserGroup.h"
#include "User.h"
#include "Meal.h"

using namespace std;

int main() {
    vector<UserGroup> groups;
    vector<User> users;
    vector<Meal> meals;

    int choice;
    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Добави група\n";
        cout << "2. Добави потребител\n";
        cout << "3. Добави ястие\n";
        cout << "4. Покажи всички\n";
        cout << "5. Запиши във файл\n";
        cout << "6. Зареди от файл\n";
        cout << "0. Изход\n";
        cout << "Избор: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            float discount;
            cout << "Име на група: ";
            cin >> ws; getline(cin, name);
            cout << "Отстъпка/надценка (%): ";
            cin >> discount;

            if (discount < -100 || discount > 100) {
                cout << "Невалиден процент!\n";
                continue;
            }

            groups.push_back(UserGroup(name, discount));
        }
        else if (choice == 2) {
            if (groups.empty()) {
                cout << "Няма групи. Създай първо група.\n";
                continue;
            }

            string username;
            int groupIndex;

            cout << "Име на потребител: ";
            cin >> ws; getline(cin, username);
            cout << "Избери група:\n";
            for (size_t i = 0; i < groups.size(); ++i)
                cout << i << ": " << groups[i] << endl;

            cin >> groupIndex;
            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Невалиден избор!\n";
                continue;
            }

            users.push_back(User(username, groups[groupIndex]));
        }
        else if (choice == 3) {
            string mealName;
            float price;
            cout << "Име на ястие: ";
            cin >> ws; getline(cin, mealName);
            cout << "Цена: ";
            cin >> price;
            meals.push_back(Meal(mealName, price));
        }
        else if (choice == 4) {
            cout << "--- Групи ---\n";
            for (auto& g : groups) cout << g << endl;

            cout << "\n--- Потребители ---\n";
            for (auto& u : users) cout << u << endl;

            cout << "\n--- Ястия ---\n";
            for (auto& m : meals) cout << m << endl;
        }

        else if (choice == 5) {
            ofstream outG("groups.txt"), outU("users.txt"), outM("meals.txt");
            if (!outG || !outU || !outM) {
                cout << "Грешка при запис във файл.\n";
                continue;
            }

            for (const auto& g : groups) g.saveToFile(outG);
            for (const auto& u : users) u.saveToFile(outU);
            for (const auto& m : meals) m.saveToFile(outM);

            cout << "Всичко е записано успешно.\n";
        }

        else if (choice == 6) {
            ifstream inG("groups.txt"), inU("users.txt"), inM("meals.txt");
            if (!inG || !inU || !inM) {
                cout << "Грешка при отваряне на файловете за четене.\n";
                continue;
            }

            groups.clear(); users.clear(); meals.clear();

            while (inG.peek() != EOF)
                groups.push_back(UserGroup::loadFromFile(inG));

            while (inU.peek() != EOF)
                users.push_back(User::loadFromFile(inU, groups));

            while (inM.peek() != EOF)
                meals.push_back(Meal::loadFromFile(inM));

            cout << "Данните са заредени успешно.\n";
        }


    } while (choice != 0);

    return 0;
}
