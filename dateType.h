#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>

using namespace std;

class dateType {
private:
    int dMonth, dDay, dYear;

public:
    dateType() : dMonth(1), dDay(1), dYear(1900) {}

    dateType(int month, int day, int year) { setDate(month, day, year); }

    void setDate(int month, int day, int year) {
        dMonth = (month >= 1 && month <= 12) ? month : 1;
        dDay = (day >= 1 && day <= 31) ? day : 1;
        dYear = (year >= 1900) ? year : 1900;
    }

    int getMonth() const { return dMonth; }
    void print() const { cout << dMonth << "-" << dDay << "-" << dYear; }
};

#endif