
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "include/LibrarySystem.h"
#include "include/LibraryException.h"
using namespace std;

void logTransaction(const string& message) {
    ofstream file("logs/transactions.txt", ios::app);
    if (file.is_open()) {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        tm* local_tm = localtime(&now_time);

        stringstream timestamp;
        timestamp << "[" << put_time(local_tm, "%Y-%m-%d %H:%M:%S") << "] ";

        file << timestamp.str() << message << endl;
        file.close();
    }
}

int main() {
    LibrarySystem system;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n2. Add Magazine\n3. Register User\n";
        cout << "4. Borrow Book\n5. Return Book\n6. View All Items\n";
        cout << "7. View All Users\n8. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        string id, title, author, userID, name;

        try {
            if (choice == 1) {
                cout << "Book ID: "; getline(cin, id);
                cout << "Title: "; getline(cin, title);
                cout << "Author: "; getline(cin, author);
                system.addBook(id, title, author);
                logTransaction("Added Book: " + id + " - \"" + title + "\"");
            } else if (choice == 2) {
                cout << "Magazine ID: "; getline(cin, id);
                cout << "Title: "; getline(cin, title);
                cout << "Author: "; getline(cin, author);
                system.addMagazine(id, title, author);
                logTransaction("Added Magazine: " + id + " - \"" + title + "\"");
            } else if (choice == 3) {
                cout << "User ID: "; getline(cin, userID);
                cout << "Name: "; getline(cin, name);
                system.registerUser(userID, name);
                logTransaction("Registered User: " + userID + " (" + name + ")");
            } else if (choice == 4) {
                cout << "User ID: "; getline(cin, userID);
                cout << "Book ID: "; getline(cin, id);
                Book* book = dynamic_cast<Book*>(system.getItem(id));
                if (!book) throw LibraryException("Book not found.");
                if (book->isBorrowed()) {
                    logTransaction("User: " + userID + " attempted to borrow Book: " + id + " - \"" + book->getTitle() + "\" - FAILED (Already borrowed)");
                    throw LibraryException("Book is already borrowed.");
                }
                system.borrowBook(userID, id);
                logTransaction("User: " + userID + " borrowed Book: " + id + " - \"" + book->getTitle() + "\"");
            } else if (choice == 5) {
                cout << "User ID: "; getline(cin, userID);
                cout << "Book ID: "; getline(cin, id);
                Book* book = dynamic_cast<Book*>(system.getItem(id));
                if (!book) throw LibraryException("Book not found.");
                system.returnBook(userID, id);
                logTransaction("User: " + userID + " returned Book: " + id + " - \"" + book->getTitle() + "\"");
            } else if (choice == 6) {
                system.viewItems();
                logTransaction("A user viewed all available items");
            } else if (choice == 7) {
                system.viewUsers();
            

            }
        } catch (const LibraryException& ex) {
            cout << "Error: " << ex.what() << endl;
        }

    } while (choice != 8);

    cout << "Program ended." << endl;
    return 0;
}
