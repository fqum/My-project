#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class User {
private:
    string userID;
    string name;
    vector<string> borrowedItems;

public:
    User() = default;
    User(const string& userID, const string& name);

    string getID() const;
    string getName() const;
    void displayInfo() const;

    void borrowItem(const string& itemID);
    void returnItem(const string& itemID);
    bool hasBorrowed(const string& itemID) const;

    friend ostream& operator<<(ostream& os, const User& user);
};

#endif