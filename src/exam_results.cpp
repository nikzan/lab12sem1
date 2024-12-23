#include "../headers/exam_results.h"
#include "../headers/sorting.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

void process_exam_results() {
    std::ifstream input("../files/students.txt");
    if (!input.is_open()) {
        std::cout << "Ошибка открытия файла 'students.txt'\n";
        return;
    }

    std::vector<std::pair<std::string, int>> students;
    std::string name;
    int score;
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        if (!(iss >> name >> score)) {
            std::cout << "Ошибка: некорректный формат данных в строке: " << line << "\n";
            input.close();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (score < 0 || score > 100) {
            std::cout << "Ошибка: балл ЕГЭ должен быть от 0 до 100 (студент: " << name << ")\n";
            input.close();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        students.push_back({name, score});
    }
    input.close();

    if (students.empty()) {
        std::cout << "Файл пуст или не содержит корректных данных\n";
        return;
    }

    quick_sort(students, 0, students.size() - 1);

    std::ofstream output("../files/sorted_students.txt");
    if (!output.is_open()) {
        std::cout << "Ошибка создания файла 'sorted_students.txt'\n";
        return;
    }

    output << std::left << std::setw(15) << "Second name" << std::right << std::setw(3) << "Score" << "\n";
    output << std::string(18, '-') << "\n";

    for(auto& student : students) {
        output << std::left << std::setfill(' ') << std::setw(15) << student.first
            << std::right << std::setw(3) << student.second << "\n";
    }
    output.close();
    std::cout << "Отсортированные результаты записаны в файл 'sorted_students.txt'\n";
}
