#include "../headers/fitness_center.h"
#include <iostream>
#include <vector>
#include <map>

struct record {
    int duration;
    int year;
    int month;
    int client_code;
};

bool validation(const record& record) {
    if (record.duration < 1 || record.duration > 30) {
        std::cout << "Ошибка: продолжительность должна быть от 1 до 30 часов\n";
        return false;
    }
    if (record.year < 2000 || record.year > 2010) {
        std::cout << "Ошибка: год должен быть между 2000 и 2010\n";
        return false;
    }
    if (record.month < 1 || record.month > 12) {
        std::cout << "Ошибка: некорректный номер месяца\n";
        return false;
    }
    if (record.client_code < 10 || record.client_code > 99) {
        std::cout << "Ошибка: код клиента должен быть между 10 и 99\n";
        return false;
    }
    return true;
}

void fitness() {
    int k, n;
    
    std::vector<record> records;
    std::map<int, std::map<int, int>> client_duration;
    
    std::cout << "Введите записи в формате: <продолжительность> <год> <месяц> <код_клиента>\n";
    for(int i = 0; i < n; i++) {
        record record;
        if (!(std::cin >> record.duration >> record.year >> record.month >> record.client_code)) {
            std::cout << "Ошибка ввода данных\n";
            return;
        }
        
        if (!validation(record)) {
            return;
        }
        
        if(record.client_code == k) {
            if(client_duration[record.year].count(record.month) == 0 ||
               client_duration[record.year][record.month] < record.duration) {
                client_duration[record.year][record.month] = record.duration;
            }
        }
    }
    
    if(client_duration.empty()) {
        std::cout << "Нет данных\n";
        return;
    }
    
    for(auto i = client_duration.rbegin(); i != client_duration.rend(); i++) {
        int max_duration = 0;
        int best_month = 13;
        
        for(const auto& month_data : i->second) {
            if(month_data.second > max_duration ||
               (month_data.second == max_duration && month_data.first < best_month)) {
                max_duration = month_data.second;
                best_month = month_data.first;
            }
        }
        
        std::cout << i->first << " " << best_month << " " << max_duration << "\n";
    }
}