#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library {
private:
    int bookID;
    string title;
    string author;
    bool issued;

public:
    void addBook() {
        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;

        ofstream file("library.txt", ios::app);

        file << bookID << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;

        file.close();

        cout << "\nBook Added Successfully!";
    }

    void displayBooks() {
        ifstream file("library.txt");

        int id;
        string t, a;
        bool isIssued;

        cout << "\n===== BOOK LIST =====\n";

        while (file >> id) {
            file.ignore();

            getline(file, t);
            getline(file, a);

            file >> isIssued;

            cout << "\nBook ID   : " << id;
            cout << "\nTitle     : " << t;
            cout << "\nAuthor    : " << a;
            cout << "\nStatus    : ";

            if (isIssued)
                cout << "Issued";
            else
                cout << "Available";

            cout << "\n----------------------";
        }

        file.close();
    }

    void searchBook() {
        ifstream file("library.txt");

        string searchTitle;
        bool found = false;

        cin.ignore();

        cout << "\nEnter Book Title to Search: ";
        getline(cin, searchTitle);

        int id;
        string t, a;
        bool isIssued;

        while (file >> id) {
            file.ignore();

            getline(file, t);
            getline(file, a);

            file >> isIssued;

            if (t == searchTitle) {
                cout << "\nBook Found!";
                cout << "\nBook ID : " << id;
                cout << "\nTitle   : " << t;
                cout << "\nAuthor  : " << a;
                cout << "\nStatus  : ";

                if (isIssued)
                    cout << "Issued";
                else
                    cout << "Available";

                found = true;
            }
        }

        if (!found) {
            cout << "\nBook Not Found!";
        }

        file.close();
    }
};

int main() {
    Library lib;

    int choice;

    do {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.displayBooks();
            break;

        case 3:
            lib.searchBook();
            break;

        case 4:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}