#include "../headers/searching.h"
#include <fstream>
#include <vector>
#include <iostream>

int binary_search_count(const std::vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int count = 0;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == x) {
            count++;
            int temp = mid - 1;
            while(temp >= 0 && arr[temp] == x) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while(temp < arr.size() && arr[temp] == x) {
                count++;
                temp++;
            }
            break;
        }
        
        if(arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return count;
}

void process_binary_search(int x) {
    std::ifstream input("../files/numbers.txt");
    if (!input.is_open()) {
        std::cout << "Ошибка открытия файла 'numbers.txt'\n";
        return;
    }
    
    std::vector<int> numbers;
    int num;
    bool valid_file = true;
    
    while(input >> num) {
        if (numbers.size() >= 200) {
            std::cout << "Превышено максимальное количество чисел (200)\n";
            valid_file = false;
            break;
        }
        numbers.push_back(num);
    }
    
    input.close();
    
    if (!valid_file) return;
    
    if (numbers.empty()) {
        std::cout << "Файл пуст или содержит некорректные данные\n";
        return;
    }
    
    // Проверка на упорядоченность
    if (!std::is_sorted(numbers.begin(), numbers.end())) {
        std::cout << "Числа в файле должны быть упорядочены по возрастанию\n";
        return;
    }
    
    int count = binary_search_count(numbers, x);
    std::cout << "Число " << x << " встречается " << count << " раз(а)\n";
}