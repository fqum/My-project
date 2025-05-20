#include "../include/LibrarySystem.h"
#include <iostream>
using namespace std;

LibraryItem* LibrarySystem::getItem(const string& id) {
    if (catalog.find(id) != catalog.end()) {
        return catalog[id].get();
    }
    return nullptr;
}


void LibrarySystem::addBook(const string& id, const string& title, const string& author) {
    catalog[id] = make_unique<Book>(title, author, id);
}

void LibrarySystem::addMagazine(const string& id, const string& title, const string& author) {
    catalog[id] = make_unique<Magazine>(title, author, id);
}

void LibrarySystem::registerUser(const string& userID, const string& name) {
    users[userID] = User(userID, name);
}

void LibrarySystem::borrowBook(const string& userID, const string& bookID) {
    if (users.count(userID) && catalog.count(bookID)) {
        Book* book = dynamic_cast<Book*>(catalog[bookID].get());
        if (book && !book->isBorrowed()) {
            book->borrow();
            users[userID].borrowItem(bookID);
        } else {
            cout << "Book is not available." << endl;
        }
    } else {
        cout << "User or Book not found." << endl;
    }
}

void LibrarySystem::returnBook(const string& userID, const string& bookID) {
    if (users.count(userID) && catalog.count(bookID)) {
        Book* book = dynamic_cast<Book*>(catalog[bookID].get());
        if (book && book->isBorrowed()) {
            book->returnBook();
            users[userID].returnItem(bookID);
        } else {
            cout << "Book was not borrowed." << endl;
        }
    } else {
        cout << "User or Book not found." << endl;
    }
}

void LibrarySystem::viewItems() const {
    for (const auto& item : catalog) {
        item.second->displayInfo();
    }
}

void LibrarySystem::viewUsers() const {
    for (const auto& user : users) {
        user.second.displayInfo();
    }
}
