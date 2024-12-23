// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "headers/sorting.h"
#include "headers/searching.h"
#include "headers/fitness_center.h"
#include "headers/exam_results.h"

void show_menu() {
    std::cout << "\nВыберите задачу:\n";
    std::cout << "1. Сортировка методом простых обменов\n";
    std::cout << "2. Бинарный поиск\n";
    std::cout << "3. Фитнес-центр\n";
    std::cout << "4. Сортировка результатов ЕГЭ\n";
    std::cout << "0. Выход\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    int choice;

    do {
        show_menu();
        while (!(std::cin >> choice) || choice < 0 || choice > 4) {
            std::cout << "Некорректный ввод. Введите число от 0 до 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(choice) {
            case 1: {
                int n;
                std::cout << "Введите размер массива: ";
                while (!(std::cin >> n) || n <= 0 || n > 1000) {
                    std::cout << "Некорректный размер. Введите число от 1 до 1000: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

                std::vector<int> arr;
                arr.reserve(n);

                std::cout << "Введите " << n << " элементов массива через пробел:" << std::endl;

                int num;
                int count = 0;
                while (count < n && std::cin >> num) {
                    arr.push_back(num);
                    count++;
                }

                if (count < n) {
                    std::cout << "Ошибка: введено недостаточно чисел\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else if (std::cin.get() != '\n') {
                    std::cout << "Ошибка: введено слишком много чисел\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    bubble_sort(arr);
                }
                break;
            }
            case 2: {
                int x;
                std::cout << "Введите искомое число: ";
                while (!(std::cin >> x)) {
                    std::cout << "Ошибка. Введите целое число: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                process_binary_search(x);
                break;
            }
            case 3: {
                fitness(); ///< валидация в самой функции
                break;
            }
            case 4: {
                process_exam_results();
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}