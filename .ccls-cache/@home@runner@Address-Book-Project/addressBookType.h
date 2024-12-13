#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>
#include "extPersonType.h"

using namespace std;

class addressBookType {
private:
    vector<extPersonType> addressList;

public:
    // Constructor
    addressBookType() {}

    // Initialize the address book from a file
    void initEntry(const string &filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        string firstName, lastName, street, city, state, phoneNumber, relationship;
        int birthMonth, birthDay, birthYear, zipCode;

        while (inFile >> firstName >> lastName) { // Read first and last name
            inFile >> birthMonth >> birthDay >> birthYear; // Read birthdate
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
            getline(inFile, street); // Read street
            getline(inFile, city); // Read city
            inFile >> state >> zipCode; // Read state and zip code
            inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline
            getline(inFile, phoneNumber); // Read phone number
            getline(inFile, relationship); // Read relationship

            extPersonType newEntry(firstName, lastName, birthMonth, birthDay, birthYear,
                                   street, city, state, zipCode, phoneNumber, relationship);
            addEntry(newEntry);
        }
        inFile.close();
    }

    // Add an entry to the address book
    void addEntry(const extPersonType &entry) {
        addressList.push_back(entry);
        sortEntries(); // Keep entries sorted by last name
    }

    // Sort entries alphabetically by last name
    void sortEntries() {
        sort(addressList.begin(), addressList.end(),
             [](const extPersonType &a, const extPersonType &b) {
                 return a.getLastName() < b.getLastName();
             });
    }

    // Find a person by last name
    void findPerson(const string &lastName) const {
        bool found = false;
        for (const auto &entry : addressList) {
            if (entry.getLastName() == lastName) {
                entry.print();
                found = true;
            }
        }
        if (!found) {
            cout << "No entry found with last name: " << lastName << endl;
        }
    }

    // Find all people with a given birth month
    void findBirthdays(int month) const {
        bool found = false;
        for (const auto &entry : addressList) {
            if (entry.getBirthMonth() == month) {
                entry.print();
                found = true;
            }
        }
        if (!found) {
            cout << "No birthdays found in month: " << month << endl;
        }
    }

    // Find all people with a specific relationship
    void findRelations(const string &relationship) const {
        bool found = false;

        for (const auto &entry : addressList) {
            string storedRelationship = entry.getRelationship();

            // Normalize both stored relationship and input for case-insensitive comparison
            string normalizedStored = storedRelationship;
            string normalizedInput = relationship;

            transform(normalizedStored.begin(), normalizedStored.end(), normalizedStored.begin(), ::tolower);
            transform(normalizedInput.begin(), normalizedInput.end(), normalizedInput.begin(), ::tolower);

            if (normalizedStored == normalizedInput) {
                entry.print();
                found = true;
            }
        }

        if (!found) {
            cout << "No entries found with relationship: " << relationship << endl;
        }
    }

    // Print all entries in the address book
    void print() const {
        if (addressList.empty()) {
            cout << "Address book is empty!" << endl;
        } else {
            for (const auto &entry : addressList) {
                entry.print();
                cout << endl;
            }
        }
    }
};

#endif
