#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <string>
#include <iostream>

using namespace std;

class addressType {
private:
    string streetAddress;
    string city;
    string state;
    int zipCode;

public:
    addressType() : streetAddress(""), city(""), state("XX"), zipCode(10000) {}

    addressType(string street, string cityName, string stateCode, int zip) {
        streetAddress = street;
        city = cityName;
        setState(stateCode);
        setZipcode(zip);
    }

    void setStreetAddress(string street) { streetAddress = street; }
    void setCity(string cityName) { city = cityName; }
    void setState(string stateCode) { state = (stateCode.length() == 2) ? stateCode : "XX"; }
    void setZipcode(int zip) { zipCode = (zip >= 11111 && zip <= 99999) ? zip : 10000; }

    void print() const {
        cout << streetAddress << endl;
        cout << city << ", " << state << " " << zipCode << endl;
    }
};

#endif