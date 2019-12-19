//
// Created by Lukas Jaklitsch on 12/16/19.
// Definition - Date class in dd/mm/yy wkdy(0-6) hr (24)

#ifndef CAPPERS_DATE_H
#define CAPPERS_DATE_H

#include "stdlib.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;
typedef std::string string;

class Date{
public:
    int day = 0;
    int month = 00;
    int year = 0000;
    int hour = 0; //24hr
    int weekday = 0; //


    //Constructortor
    Date() = default;

    //Copy Constructor
    Date(const Date & date) = default;

    //Assignment Operator
    Date & operator=(const Date & date);

    // Alt Constructor
    Date(int day, int mnth, int yr, int hr = 0);

    // Set Date to todays date
    void setToday();

    bool operator>(const Date& tmp_date);
    bool operator>=(const Date& tmp_date);
    bool operator<(const Date& tmp_date);
    bool operator<=(const Date& tmp_date);
    bool operator==(const Date& tmp_date);
    bool operator!=(const Date& tmp_date);
    void print();

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};
#endif //CAPPERS_DATE_H
