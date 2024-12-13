#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>
#include <iostream>

using namespace std;

class personType {
private:
    string firstName;
    string lastName;

public:
    personType(string first = "", string last = "") : firstName(first), lastName(last) {}

    void setFirstName(const string &first) { firstName = first; }
    string getFirstName() const { return firstName; }
    void setLastName(const string &last) { lastName = last; }
    string getLastName() const { return lastName; }

    void print() const { cout << firstName << " " << lastName << endl; }
};

#endif