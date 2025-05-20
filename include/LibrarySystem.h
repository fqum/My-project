#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <map>
#include <memory>
#include "LibraryItem.h"
#include "User.h"
#include "Book.h"
#include "Magazine.h"

using namespace std;

class LibrarySystem {
private:
    map<string, unique_ptr<LibraryItem>> catalog;
    map<string, User> users;
  


public:
    void addBook(const string& id, const string& title, const string& author);
    void addMagazine(const string& id, const string& title, const string& author);
    void registerUser(const string& userID, const string& name);
    void borrowBook(const string& userID, const string& bookID);
    void returnBook(const string& userID, const string& bookID);
    void viewItems() const;
    void viewUsers() const;
    LibraryItem* getItem(const string& id);
};

#endif
