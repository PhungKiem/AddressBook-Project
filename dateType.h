#include <iostream>
using namespace std;

// Define the dateType class
class dateType {
private:
    int dMonth;
    int dDay;
    int dYear;

public:
    // Default constructor
    dateType() : dMonth(1), dDay(1), dYear(1900) {}

    // Parameterized constructor
    dateType(int month, int day, int year) {
        setDate(month, day, year);
    }

    // Sets the date with validation
    void setDate(int month, int day, int year) {
        if (year < 1900) {
            dMonth = 1;
            dDay = 1;
            dYear = 1900;
            cout << "Date invalid, setting to 1/1/1900" << endl;
            return;
        }
        if (month < 1 || month > 12) {
            dMonth = 1;
            dDay = 1;
            dYear = 1900;
            cout << "Date invalid, setting to 1/1/1900" << endl;
            return;
        }

        int daysInMonth = getDaysInMonth(month, year);
        if (day < 1 || day > daysInMonth) {
            dMonth = 1;
            dDay = 1;
            dYear = 1900;
            cout << "Date invalid, setting to 1/1/1900" << endl;
            return;
        }

        dMonth = month;
        dDay = day;
        dYear = year;
    }

    // Function to get the number of days in a month
    int getDaysInMonth(int month, int year) const {
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        return 31;
    }

    // Function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Function to print the date
    void print() const {
        cout << dMonth << "-" << dDay << "-" << dYear;
    }
};