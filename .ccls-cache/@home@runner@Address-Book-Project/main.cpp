#include "addressBookType.h"
#include <iostream>
#include <fstream>

using namespace std;

int showMenu() {
    int choice;
    cout << "Address Book\n";
    cout << "1 – Display all entries.\n";
    cout << "2 – Find person by name.\n";
    cout << "3 – Find birthdays by month.\n";
    cout << "4 – Find entries by relationship.\n";
    cout << "5 – Quit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    addressBookType addressBook;
    string filename = "AddressBookData.txt";

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    
    addressBook.initEntry(filename);


    int choice;
    do {
        choice = showMenu();
        string lastName, relationship;
        int month;

        switch (choice) {
            case 1:
                addressBook.print();
                break;

            case 2:
                cout << "Enter the last name(Caps Sensitve): ";
                cin >> lastName;
                addressBook.findPerson(lastName);
                break;

            case 3:
                cout << "Enter the birth month (1-12): ";
                cin >> month;
                if (month < 1 || month > 12) {
                    cout << "Invalid month. Please enter a value between 1 and 12." << endl;
                } else {
                    addressBook.findBirthdays(month);
                }
                break;

            case 4:
                cout << "Enter the relationship (Business, Friend, Family): ";
                cin >> relationship;
                addressBook.findRelations(relationship);
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
