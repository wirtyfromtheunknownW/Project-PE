#include <iostream>
#include <vector>
#include <fstream>
#include "loop.h"
#include "User.h"
#include "UserGroup.h"
#include "Meal.h"
#include "order.h"

using namespace std;

void runMenu() {
    vector<UserGroup> groups;
    vector<User> users;
    vector<Meal> meals;
    vector<Order> orders;
    
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Group\n";
        cout << "2. Add User\n";
        cout << "3. Add Meal\n";
        cout << "4. Show All\n";
        cout << "5. Save to File\n";
        cout << "6. Load File\n";
        cout << "7. Make Order\n";
        cout << "8. Show All Orders\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            float discount;
            cout << "Name Of Group: ";
            cin >> ws; getline(cin, name);
            cout << "Discount (%): ";
            cin >> discount;

            if (discount < -100 || discount > 100) {
                cout << "Invalid Percentage!\n";
                continue;
            }

            groups.push_back(UserGroup(name, discount));
        }
        else if (choice == 2) {
            if (groups.empty()) {
                cout << "No Groups. Create New One First.\n";
                continue;
            }

            string username;
            int groupIndex;

            cout << "Name Of User: ";
            cin >> ws; getline(cin, username);
            cout << "Choose a Group:\n";
            for (size_t i = 0; i < groups.size(); ++i)
                cout << i << ": " << groups[i] << endl;

            cin >> groupIndex;
            if (groupIndex < 0 || groupIndex >= groups.size()) {
                cout << "Invalid Choice!\n";
                continue;
            }

            users.push_back(User(username, groups[groupIndex]));
        }
        else if (choice == 3) {
            string mealName;
            float price;
            cout << "Name Of Meal: ";
            cin >> ws; getline(cin, mealName);
            cout << "Price: ";
            cin >> price;
            meals.push_back(Meal(mealName, price));
        }
        else if (choice == 4) {
            cout << "--- Groups ---\n";
            for (const auto& g : groups) cout << g << endl;

            cout << "\n--- Users ---\n";
            for (const auto& u : users) cout << u << endl;

            cout << "\n--- Meals ---\n";
            for (const auto& m : meals) cout << m << endl;
        }
        else if (choice == 5) {
            ofstream outG("groups.txt"), outU("users.txt"), outM("meals.txt");
            if (!outG || !outU || !outM) {
                cout << "Error While Saving To File.\n";
                continue;
            }

            for (const auto& g : groups) g.saveToFile(outG);
            for (const auto& u : users) u.saveToFile(outU);
            for (const auto& m : meals) m.saveToFile(outM); 
            cout << "Succesfull Save.\n";
        }
        else if (choice == 6) {
            ifstream inG("groups.txt"), inU("users.txt"), inM("meals.txt");
            if (!inG || !inU || !inM) {
                cout << "Error While Opening File.\n";
                continue;
            }

            groups.clear(); users.clear(); meals.clear();

            while (inG.peek() != EOF)
                groups.push_back(UserGroup::loadFromFile(inG));

            while (inU.peek() != EOF)
                users.push_back(User::loadFromFile(inU, groups));

            while (inM.peek() != EOF)
                meals.push_back(Meal::loadFromFile(inM));

            cout << "Data Loaded Succesfully.\n";
        }
        else if (choice == 7) {
            if (users.empty() || meals.empty()) {
                cout << "User and Meal Needed, For a Order.\n";
                continue;
            }

            cout << "Choose User:\n";
            for (size_t i = 0; i < users.size(); ++i)
                cout << i << ": " << users[i] << endl;
            int uIndex;
            cin >> uIndex;

            cout << "Choose Meal:\n";
            for (size_t i = 0; i < meals.size(); ++i)
                cout << i << ": " << meals[i] << endl;
            int mIndex;
            cin >> mIndex;

            if (uIndex < 0 || uIndex >= users.size() || mIndex < 0 || mIndex >= meals.size()) {
                cout << "Invalid Choice.\n";
                continue;
            }

            Order o(users[uIndex], meals[mIndex]);
            orders.push_back(o);
            cout << "Order Complete: " << o << endl;
        }
        else if (choice == 8) {
            cout << "--- All Orders ---\n";
            for (const auto& o : orders)
                cout << o << endl;
        }


    } while (choice != 0);
}
