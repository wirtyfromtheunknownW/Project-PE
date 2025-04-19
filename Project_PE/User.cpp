#include "User.h"
#include <fstream>
#include <vector>

User::User() : username(""), group() {}
User::User(std::string u, UserGroup g) : username(u), group(g) {}

void User::setUsername(std::string u) { username = u; }
void User::setGroup(UserGroup g) { group = g; }
std::string User::getUsername() const { return username; }
UserGroup User::getGroup() const { return group; }

std::ostream& operator<<(std::ostream& out, const User& u) {
    out << "User: " << u.username << " (" << u.group.getName() << ")";
    return out;
}


void User::saveToFile(std::ofstream& out) const {
    out << username << '\n' << group.getName() << '\n';
}

User User::loadFromFile(std::ifstream& in, const std::vector<UserGroup>& groups) {
    std::string username, groupName;
    std::getline(in, username);
    std::getline(in, groupName);

    for (const auto& g : groups) {
        if (g.getName() == groupName)
            return User(username, g);
    }

    return User(username, UserGroup(groupName, 0.0f));
}

