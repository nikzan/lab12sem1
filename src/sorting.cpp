#include "../headers/sorting.h"
#include <fstream>
#include <iostream>

void bubble_sort(std::vector<int>& arr) {
    std::ofstream file("../files/sorted.txt");
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла для записи лога сортировки\n";
        return;
    }
    int n = arr.size();
    file << "Начальный массив: ";
    for(int i = 0; i < n; i++) {
        file << arr[i] << " ";
    }
    file << "\n\n";
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
        file << "Итерация " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            file << arr[k] << " ";
            if (k == i) {
                file << "| ";
            }
        }
        file << "\n";
    }

    file << "\nОтсортированный массив: ";
    for(int i = 0; i < n; i++) {
        file << arr[i] << " ";
    }
    file << "\n";

    file.close();
    std::cout << "Результаты сортировки записаны в файл 'sorted.txt'\n";
}

void quick_sort(std::vector<std::pair<std::string, int>>& data, int left, int right) {
    if(left < right) {
        std::string pivot = data[(left + right) / 2].first;
        int i = left, j = right;

        while(i <= j) {
            while(data[i].first < pivot) i++;
            while(data[j].first > pivot) j--;
            if(i <= j) {
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        if(left < j) quick_sort(data, left, j);
        if(i < right) quick_sort(data, i, right);
    }
}