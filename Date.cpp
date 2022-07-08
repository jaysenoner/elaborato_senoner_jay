//
// Created by jayse on 07/07/2022.
//

#include "Date.h"

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

//Prints the date in the standard italian format+
void  Date::printDate() const  {

    std::cout<<this->day<<"/"<<this->month<<"/"<<this->year<<std::endl;

}

//Checks if the given date is valid or not
bool Date::isValidDate(int day,int month,int year) const {

    return day > 0 && day <= getMaxNumOfDays(month, year) &&
           month > 0 && month <= 12 &&
           year > minimum_date_year && year <= current_date_year;

}

//Returns the max number of days of a certain month in a given year
int Date::getMaxNumOfDays(int month, int year) {
    int maxDays[13] = { 0, 31, 28, 31, 30,
                        31, 30, 31, 31, 30,
                        31, 30, 31 };

    //Checking if month is February and if its a leap year or not

        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            return 29;
        }
        return maxDays[month];
    }

bool Date::operator==(const Date &d) const {
    return this->day == d.day && this->month == d.month && this->year == d.year;
}

