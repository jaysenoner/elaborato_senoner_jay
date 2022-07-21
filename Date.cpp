//
// Created by jayse on 07/07/2022.
//

#include "Date.h"

int Date::getDay() const {
    return day;
}

bool Date::setDay(int day) {
    if(day > 0 && day <= getMaxNumOfDays(month, year)){
        Date::day = day;
        return true;
    }
    else return false;

}

int Date::getMonth() const {
    return month;
}

bool Date::setMonth(int month) {
    if( month > 0 && month <= 12){
        Date::month = month;
        return true;
    }
    else return false;

}

int Date::getYear() const {
    return year;
}

bool Date::setYear(int year) {
    if(year > minimum_date_year && year <= current_date_year){
        Date::year = year;
        return true;
    }
    else return false;
}

//Prints the date in the standard italian format
void  Date::printDate() const  {

    std::cout<<this->day<<"/"<<this->month<<"/"<<this->year<<std::endl;

}

std::string Date::dateToString() const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

//Checks if the given date is valid or not
 bool Date::isValidDate(int day,int month,int year)  {

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


