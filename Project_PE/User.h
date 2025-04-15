#pragma once
#include <iostream>
#include <string>
#include "UserGroup.h"
#include <fstream>  
#include <vector>

class User {
private:
    std::string username;
    UserGroup group;

public:
    User();
    User(std::string, UserGroup);

    void setUsername(std::string);
    void setGroup(UserGroup);
    std::string getUsername() const;
    UserGroup getGroup() const;

    void saveToFile(std::ofstream&) const;
    static User loadFromFile(std::ifstream&, const std::vector<UserGroup>&);
    friend std::ostream& operator<<(std::ostream&, const User&);
};
