#include <iostream>
#include <string>
#include "personType.h"
#include "dateType.h"
#include "addressType.h"

using namespace std;

class extPersonType : public personType {
private:
    dateType birthdate;
    addressType address;
    string phoneNumber;
    string relationship;

public:
    // Constructor with default values
    extPersonType(string first = "", string last = "", int month = 1, int day = 1, int year = 1900,
                  string street = "", string city = "", string state = "", int zip = 10000,
                  string phone = "", string rel = "Friend")
        : personType(first, last), birthdate(month, day, year), address(street, city, state, zip), phoneNumber(phone)
    {
        setRelationship(rel); // Initialize and validate relationship
    }

    // Setter for phoneNumber
    void setPhoneNumber(const string &phone) {
        phoneNumber = phone;
    }

    // Getter for phoneNumber
    string getPhoneNumber() const {
        return phoneNumber;
    }

    // Setter for relationship (with validation)
    void setRelationship(const string &rel) {
        if (rel == "Family" || rel == "Friend" || rel == "Business") {
            relationship = rel;
        } else {
            relationship = "";  // Invalid relationships set to empty string
            cout << "Invalid relationship value!" << endl;
        }
    }

    // Getter for relationship
    string getRelationship() const {
        return relationship;
    }

    // Print function
    void print() const {
        personType::print();  // Print name
        birthdate.print();    // Print birth date
        address.print();      // Print address
        cout << phoneNumber << endl;
        if (!relationship.empty()) {
            cout << relationship << endl;
        }
    }
};