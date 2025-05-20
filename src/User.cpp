#include "../include/User.h"
using namespace std;

User::User(const string& userID, const string& name)
    : userID(userID), name(name) {}

string User::getID() const { return userID; }

string User::getName() const { return name; }

void User::displayInfo() const {
    cout << *this << endl;
}

void User::borrowItem(const string& itemID) {
    borrowedItems.push_back(itemID);
}

void User::returnItem(const string& itemID) {
    for (auto it = borrowedItems.begin(); it != borrowedItems.end(); ++it) {
        if (*it == itemID) {
            borrowedItems.erase(it);
            break;
        }
    }
}

bool User::hasBorrowed(const string& itemID) const {
    for (const string& item : borrowedItems) {
        if (item == itemID) return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "User: " << user.name << " [ID: " << user.userID << "]\n";
    if (user.borrowedItems.empty()) {
        os << "  No borrowed items.";
    } else {
        os << "  Borrowed items: ";
        for (const string& item : user.borrowedItems) {
            os << item << " ";
        }
    }
    return os;
}
