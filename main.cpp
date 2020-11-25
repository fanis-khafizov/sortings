#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "DataArray.h"
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string path = "/home/fanis/CLionProjects/sortings/";
    std::vector<std::string> file_names = {"data100.txt", "data500.txt", "data1000.txt",
                                           "data5000.txt", "data10000.txt", "data20000.txt",
                                           "data50000.txt", "data100000.txt", "data200000.txt",
                                           "data500000.txt"};
    std::string output_file = "/home/fanis/CLionProjects/sortings/output.txt";
    std::ofstream fout(output_file);
    unsigned long long start, finish;
    DataArray *data;
    for (auto file: file_names) {
        data = new DataArray(path + file);
        start = clock();
        data->shaker_sort();
        finish = clock();
        fout << finish - start << ';';
        delete data;

        data = new DataArray(path + file);
        start = clock();
        data->heap_sort();
        finish = clock();
        fout << finish - start << ';';
        delete data;

        data = new DataArray(path + file);
        start = clock();
        data->quick_sort();
        finish = clock();
        fout << finish - start << std::endl;
        delete data;
    }
    return 0;
}
