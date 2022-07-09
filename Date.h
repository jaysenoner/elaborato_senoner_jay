//
// Created by jayse on 07/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_DATE_H
#define ELABORATO_SENONER_JAY_DATE_H


#include <iostream>

class Date {

private:

    int day;
    int month;
    int year;
    static int getMaxNumOfDays(int month,int year);
    static const int minimum_date_year = 1900;
    static const int current_date_year = 2022;


public:
    static bool isValidDate(int day,int month,int year) ;
    std::string dateToString() const;
    void printDate() const;
    Date() = default;
    Date(int day,int month,int year) {
        if(isValidDate(day,month,year)){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        else std::cerr<<"Insert a valid date!"<<std::endl;

    }


    //Getters and Setters
    int getDay() const;
    void setDay(int day);
    int getMonth() const;
    void setMonth(int month);
    int getYear() const;
    void setYear(int year);
    bool operator==(const Date& d) const;

};


#endif //ELABORATO_SENONER_JAY_DATE_H
