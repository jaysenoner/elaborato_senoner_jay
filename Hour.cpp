//
// Created by jayse on 13/07/2022.
//

#include "Hour.h"



std::string Hour::hourToString() const {
    std::string tmpString;
    if(hour<10)
        tmpString = "0" + std::to_string(hour);
    else tmpString = std::to_string(hour);

    tmpString += ":";
    if(min<10)
        tmpString += "0" + std::to_string(min);
    else tmpString += std::to_string(min);
    return tmpString;
}

void Hour::setHour(int hour) {
    Hour::hour = hour;
}

void Hour::setMin(int min) {
    Hour::min = min;
}

bool Hour::operator==(const Hour &right) const{
    return (hour == right.hour && min == right.min);
}
