//
// Created by fanis on 24.11.2020.
//

#include "DataArray.h"

DataArray::DataArray() {}

DataArray::DataArray(std::string fileName) {
    std::ifstream fin(fileName);
    if (!fin.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }
    std::string country, clubName, city, coach, year, points;
    while (!fin.eof()) {
        std::getline(fin, country, ';');
        std::getline(fin, clubName, ';');
        std::getline(fin, city, ';');
        std::getline(fin, year, ';');
        std::getline(fin, coach, ';');
        std::getline(fin, points, '\n');
        Data* new_data = new Data(country, clubName, city, std::stoi(year), coach, std::stoi(points));
        Array.push_back(new_data);
    }
}

DataArray::DataArray(std::vector<Data*>& data) {
    Array = data;
}

DataArray::~DataArray() {
    Array.clear();
}

Data DataArray::operator[] (int index) {
    return *Array[index];
}

void DataArray::shaker_sort() {
    ShakerSort(Array);
}

void DataArray::heap_sort() {
    HeapSort(Array);
}

void DataArray::quick_sort() {
    QuickSort(Array);
}