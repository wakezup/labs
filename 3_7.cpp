#include <iostream>

#include "input_utils.h"


void Square(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {
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

    std::cout << "[РЕЗУЛЬТАТ] Квадрат из " << x << " строк и " << x
              << " столбцов:" << '\n';
    Square(x);

    return 0;
}