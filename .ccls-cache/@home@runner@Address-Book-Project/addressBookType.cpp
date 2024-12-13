#include "addressBookType.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

addressBookType::addressBookType(int size) : maxSize(size) {}

void addressBookType::initEntry(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    while (!inFile.eof() && addressList.size() < maxSize) {
        extPersonType person;
        inFile >> person.firstName >> person.lastName 
               >> person.birthMonth >> person.birthDay >> person.birthYear 
               >> ws;
        getline(inFile, person.address);
        getline(inFile, person.city);
        inFile >> person.state >> person.zipCode >> person.phoneNumber 
               >> person.relationship;
        addressList.push_back(person);
    }
    inFile.close();
}

void addressBookType::addEntry(const extPersonType& newEntry) {
    if (addressList.size() >= maxSize) {
        cerr << "Address book is full. Cannot add more entries." << endl;
        return;
    }
    addressList.push_back(newEntry);
}

void addressBookType::findPerson(const string& lastName) const {
    for (const auto& person : addressList) {
        if (person.lastName == lastName) {
            person.print();
            return;
        }
    }
    cout << "Person with last name '" << lastName << "' not found." << endl;
}

void addressBookType::findBirthdays(int month) const {
    for (const auto& person : addressList) {
        if (person.birthMonth == month) {
            person.print();
        }
    }
}

void addressBookType::findRelations(const string& relationship) const {
    for (const auto& person : addressList) {
        if (person.relationship == relationship) {
            person.print();
        }
    }
}

void addressBookType::print() const {
    for (const auto& person : addressList) {
        person.print();
    }
}

void addressBookType::sortEntries() {
    sort(addressList.begin(), addressList.end(), [](const extPersonType& a, const extPersonType& b) {
        return a.lastName < b.lastName;
    });
}