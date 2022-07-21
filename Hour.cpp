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

bool Hour::setHour(int hour) {
    if(hour>=0 && hour<24){
        Hour::hour = hour;
        return true;
    }
    else return false;


}

bool Hour::setMin(int min) {
    if(min>=0 && min<60) {
        Hour::min = min;
        return true;
    }
    else return false;
}

bool Hour::operator==(const Hour &right) const{
    return (hour == right.hour && min == right.min);
}
