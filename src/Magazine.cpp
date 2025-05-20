
#include "../include/Magazine.h"
#include <iostream>

using namespace std;

Magazine::Magazine(const string& title, const string& author, const string& itemID)
    : LibraryItem(title, author, itemID)
{

}

void Magazine::displayInfo() const {
    cout << "Magazine: " << title << " by " << author
         << " [ID: " << itemID << "] - Not Borrowable" << endl;
}

bool Magazine::isBorrowable() const {
    return false;
}
