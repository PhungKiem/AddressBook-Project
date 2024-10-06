#include <iostream>
#include <string>

using namespace std;

class personType {
private:
    string firstName;
    string lastName;

public:
    // Default constructor
    personType(string first = "", string last = "") 
        : firstName(first), lastName(last) {}

    // Setter for firstName
    void setFirstName(const string &first) {
        firstName = first;
    }

    // Getter for firstName
    string getFirstName() const {
        return firstName;
    }

    // Setter for lastName
    void setLastName(const string &last) {
        lastName = last;
    }

    // Getter for lastName
    string getLastName() const {
        return lastName;
    }

    // Function to print the person's name
    void print() const {
        cout << firstName << " " << lastName << endl;
    }
};