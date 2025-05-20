#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    string itemID;

public:
    LibraryItem(const string& title, const string& author, const string& itemID)
        : title(title), author(author), itemID(itemID) {}

    virtual ~LibraryItem() {}

    string getID() const { return itemID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    virtual void displayInfo() const = 0;
    virtual bool isBorrowable() const = 0;
};

#endif
