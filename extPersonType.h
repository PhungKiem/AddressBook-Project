#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class extPersonType : public personType {
private:
    dateType birthdate;
    addressType address;
    string phoneNumber;
    string relationship;

public:
    extPersonType(string first = "", string last = "", int month = 1, int day = 1, int year = 1900,
                  string street = "", string city = "", string state = "", int zip = 10000,
                  string phone = "", string rel = "Friend")
        : personType(first, last), birthdate(month, day, year), address(street, city, state, zip), phoneNumber(phone), relationship(rel) {}


    void setPhoneNumber(const string &phone) { phoneNumber = phone; }
    string getPhoneNumber() const { return phoneNumber; }

    string getRelationship() const { return relationship; }

    int getBirthMonth() const { return birthdate.getMonth(); }  
    dateType getBirthDate() const { return birthdate; } 

    void print() const {
        personType::print();
        birthdate.print();
        cout << endl;
        address.print();
        cout << "Phone: " << phoneNumber << endl;
        cout << "Relationship: " << relationship << endl;
    
    }
};

#endif