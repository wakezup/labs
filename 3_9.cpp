#include <iostream>

#include "input_utils.h"


void RightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x - i; ++j) {
            std::cout << "  ";
        }
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

int main() {
    int x;

    std::cout << "[ВВОД] Введите целое положительное число: ";
    if (!(std::cin >> x) || !IsInputLineClean() || x <= 0) {
        std::cout << "[ОШИБКА] Введенное значение не является целым "
                     "положительным числом!"
                  << '\n';
        return 1;
    }

    std::cout << "[РЕЗУЛЬТАТ] Прямоугольный треугольник с " << x
              << " строками:" << '\n';
    RightTriangle(x);

    return 0;
}