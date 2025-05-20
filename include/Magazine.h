#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
public:
    Magazine(const string& title, const string& author, const string& itemID);

    void displayInfo() const override;
    bool isBorrowable() const override;
};

#endif
