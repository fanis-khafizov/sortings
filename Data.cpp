//
// Created by fanis on 06.11.2020.
//

#include "Data.h"

Data::Data(){};

Data::Data(std::string country, std::string clubName, std::string city, int year, std::string coach, int points) {
    Country = country;
    ClubName = clubName;
    City = city;
    Year = year;
    Coach = coach;
    Points = points;
};

Data::~Data(){};

bool Data::operator>(Data &info) {
    if (Year != info.Year) return Year > info.Year;
    else if (Points != info.Points) return Points > info.Points;
    else return ClubName > info.ClubName;
}

bool Data::operator<(Data &info) {
    if (Year != info.Year) return Year < info.Year;
    else if (Points != info.Points) return Points < info.Points;
    else return ClubName < info.ClubName;
}

bool Data::operator>=(Data &info) {
    return !(*this < info);
}

bool Data::operator<=(Data &info) {
    return !(*this > info);
}

bool Data::operator==(Data &info) {
    return (Year == info.Year) && (Points == info.Points) && (ClubName == info.ClubName);
}

bool Data::operator!=(Data &info) {
    return !(*this == info);
}