#include <iostream>
#include <vector>
#include "Data.h"
#include "sortings.cpp"
#include <cstdlib>
int main() {
    /*
    Data d1("1", "1", "1", 1, "1", 1);
    Data d2("2", "2", "2", 2, "2", 2);
    std::cout << (d1 > d2) << std::endl;
    std::cout << (d1 < d2) << std::endl;
    */
    std::vector<int*> v(10);
    int arr[v.size()];
    for (int i = 0; i < v.size(); i++) {
        arr[v.size() - i - 1] = rand() % 100;
        v[i] = &arr[i];
    }
    for (int i = 0; i < v.size(); i++) std::cout << *v[i] << ' ';
    std::cout << std::endl;
    QuickSort(v);
    for (int i = 0; i < v.size(); i++) std::cout << *v[i] << ' ';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
