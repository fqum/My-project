#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <iostream>
using namespace std;

class Book : public LibraryItem {
private:
    bool borrowed;

public:
    Book(const string& title, const string& author, const string& itemID);

    void displayInfo() const override;
    bool isBorrowable() const override;
    bool isBorrowed() const;
    void borrow();
    void returnBook();

    friend ostream& operator<<(ostream& os, const Book& book);
};

#endif