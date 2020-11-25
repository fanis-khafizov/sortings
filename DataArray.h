//
// Created by fanis on 24.11.2020.
//

#ifndef SORTINGS_DATAARRAY_H
#define SORTINGS_DATAARRAY_H

#include "Data.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "sortings.cpp"

class DataArray {
private:
    std::vector<Data*> Array;
public:
    DataArray();
    DataArray(std::string fileName);
    DataArray(std::vector<Data*>& data);
    ~DataArray();
    Data operator[] (int index);
    void shaker_sort();
    void quick_sort();
    void heap_sort();
};


#endif //SORTINGS_DATAARRAY_H
