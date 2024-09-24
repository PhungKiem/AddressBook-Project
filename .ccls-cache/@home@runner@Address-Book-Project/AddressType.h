#pragma once
#include <iostream>
using namespace std;

class addressType
{
public:
    void printAddress() const;
    void setAddress(string street, string city, string state, string zip);

    addressType(string street = "", string city = "", string state = "", string zip = "");

private:
    string streetAddress;
    string city;
    string state;
    string zipCode;
};