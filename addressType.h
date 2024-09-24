#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class addressType {
private:
    string streetAddress;
    string city;
    string state;
    int zipCode;

public:
    // Default constructor
    addressType() : streetAddress(""), city(""), state("XX"), zipCode(10000) {}

    // Constructor with parameters
    addressType(string street, string cityName, string stateCode, int zip) {
        streetAddress = street;
        city = cityName;
        setState(stateCode);
        setZipcode(zip);
    }

    // Function to set the street address
    void setStreetAddress(string street) {
        streetAddress = street;
    }

    // Function to set the city
    void setCity(string cityName) {
        city = cityName;
    }

    // Function to set the state
    void setState(string stateCode) {
        if (stateCode.length() == 2) {
            state = stateCode;
        } else {
            state = "XX";
        }
    }

    // Function to set the zipcode
    void setZipcode(int zip) {
        if (zip >= 11111 && zip <= 99999) {
            zipCode = zip;
        } else {
            zipCode = 10000;
        }
    }

    // Combined function to set all address fields
void setAddress(string street, string cityName, string stateCode, int zip) {
    setStreetAddress(street);
    setCity(cityName);
    setState(stateCode);
    setZipcode(zip);

}
    // Function to print the address in the standard format
    void print() const {
        cout << streetAddress << endl;
        cout << city << endl;
        cout << state << endl;
        cout << zipCode << endl;
    }
};