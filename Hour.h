//
// Created by jayse on 13/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_HOUR_H
#define ELABORATO_SENONER_JAY_HOUR_H


#include <iostream>

class Hour {
private:
    int hour;
    int min;
public:
    Hour() = default;
    Hour(int hour ,int min ) {
        if( (hour>=0 && hour<24 ) && (min>=0 && min<60)){
            this->hour = hour;
            this->min = min;
        }
        else {
            throw std::runtime_error("Insert a valid hour!");
        }

    }
    std::string hourToString() const;
    void setHour(int hour);
    void setMin(int min);
    bool operator==(const Hour& right) const;

};


#endif //ELABORATO_SENONER_JAY_HOUR_H
