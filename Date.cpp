//
// Created by Lukas Jaklitsch on 12/16/19.
// implements the date class

#include "Date.h"

Date::Date(int dy, int mnth, int yr, int hr):
            day(dy), month(mnth), year(yr), hour(hr), weekday(0){};

Date & Date::operator=(const Date & date){
    if(this != & date){
        day = date.day;
        month = date.month;
        year = date.year;
        hour = date.hour;
        weekday = date.weekday;
    }
    return *this;
};


void Date::setToday(){

    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    year = 1900 + timePtr->tm_year;
    month = 1 + timePtr->tm_mon;
    day = timePtr->tm_mday;
    hour = timePtr->tm_hour;
    weekday = timePtr->tm_wday;
}

// returns true if this date is before tmp_date
bool Date::operator>(const Date& tmp_date){
    if(year > tmp_date.year){
        return true;
    }

    if(year == tmp_date.year) {
        if (month > tmp_date.month) {
            return true;
        }
        if(month == tmp_date.month) {
            return day > tmp_date.day;
        }
    }
    return false;
};

// returns if this date is later than tmp_date

bool Date::operator<(const Date& tmp_date){
    if(year < tmp_date.year){
        return true;
    }

    if(year == tmp_date.year) {
        if (month < tmp_date.month) {
            return true;
        }
        if(month == tmp_date.month) {
            return day < tmp_date.day;
        }
    }
    return false;
};


bool Date::operator==(const Date& tmp_date){
    return day == tmp_date.day && month == tmp_date.month && year == tmp_date.year;
};

bool Date::operator!=(const Date& tmp_date){
    return day != tmp_date.day || month != tmp_date.month || year != tmp_date.year;
};

bool Date::operator>=(const Date& tmp_date){return *this > tmp_date || *this == tmp_date;};

bool Date::operator<=(const Date& tmp_date){return *this < tmp_date || *this == tmp_date;};

void Date::print(){ std::cout<< this->day << "/" << this->month<< "/" << this->year<< "\n";};

void Date::setDay(int d)
{
    if (d < 1 || d > 31) {
        std::cout << "The day is invalid" << std::endl;
    }else {
        day = d;
    }
}

void Date::setMonth(int m)
{
    if (m < 1 || m > 12) {
        std::cout << "The month is invalid" << std::endl;
    }else {
        month = m;
    }
}

void Date::setYear(int y)
{
    if (y < 1){
        std::cout << "The year is invalid" << std::endl;
    } else{
        year = y;
    }
}