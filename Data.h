//
// Created by fanis on 06.11.2020.
//

#ifndef SORTINGS_DATA_H
#define SORTINGS_DATA_H

#include <string>

class Data {
private:
    std::string Country;
    std::string ClubName;
    std::string City;
    int Year;
    std::string Coach;
    int Points;
public:
    Data();
    Data(std::string country, std::string clubName, std::string city, int year, std::string coach, int points);
    ~Data();
    bool operator>(Data &info);
    bool operator<(Data &info);
    bool operator>=(Data &info);
    bool operator<=(Data &info);
    bool operator==(Data &info);
    bool operator!=(Data &info);
};


#endif //SORTINGS_DATA_H
