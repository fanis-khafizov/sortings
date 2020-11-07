//
// Created by fanis on 06.11.2020.
//
#include <vector>
#include <iostream>

template<typename T>

void ShakerSort(std::vector<T*>& data) {
    int begin = 0;
    int end = data.size() - 1;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = begin; i < end; i++) {
            if (*data[i] > *data[i + 1]) {
                std::swap(data[i], data[i + 1]);
                swapped = true;
            }
        }
        end--;
        for (int i = end; i > begin; i--) {
            if (*data[i] < *data[i - 1]) {
                std::swap(data[i], data[i - 1]);
                swapped = true;
            }
        }
        begin++;
    }
}

template<typename T>

void createHeap(std::vector<T*>& data, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n) {
        if (*data[largest] < *data[left]) largest = left;
    }

    if (right < n) {
        if (*data[largest] < *data[right]) largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        createHeap(data, n, largest);
    }
}

template<typename T>

void HeapSort(std::vector<T*>& data) {
    for (int i = data.size() / 2 - 1; i >= 0; i--) {
        createHeap(data, data.size(), i);
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        std::swap(data[0], data[i]);
        createHeap(data, i, 0);
    }
}

template <typename T>

void QSort(std::vector<T*>& data, int low, int high) {
    if (low >= high) return;
    int left = low;
    T* pivot = data[(low + high) / 2];
    std::swap(data[(low + high) / 2], data[left]);
    for (int i = low; i <= high; i++) {
        if (*data[i] < *pivot) {
            std::swap(data[i], data[left]);
            left++;
        }
    }
    for (int i = left; i < data.size(); i++) {
        if (*data[i] == *pivot) {
            std::swap(data[i], data[left]);
            break;
        }
    }
    QSort(data, low, left - 1);
    QSort(data, left + 1,  high);
}

template <typename T>

void QuickSort(std::vector<T*>& data) {
    QSort(data, 0, data.size() - 1);
}