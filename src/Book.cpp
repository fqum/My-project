#include "../include/Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& title, const string& author, const string& itemID)
    : LibraryItem(title, author, itemID), borrowed(false) {}

void Book::displayInfo() const {
    cout << *this << endl;
}

bool Book::isBorrowable() const { return true; }

bool Book::isBorrowed() const { return borrowed; }

void Book::borrow() { borrowed = true; }

void Book::returnBook() { borrowed = false; }

ostream& operator<<(ostream& os, const Book& book) {
    os << "Book: " << book.title << " by " << book.author
       << " [ID: " << book.itemID << "]";
    os << (book.borrowed ? " - Status: Borrowed" : " - Status: Available");
    return os;
}
