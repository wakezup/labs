#include <iostream>

#include "input_utils.h"

double Fraction(double x) {
    int integer_part = static_cast<int>(x);
    return x - integer_part;
}

int main() {
    double x;

    std::cout << "[ВВОД] Введите число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является числом!" << '\n';
        return 1;
    }
    std::cout << "[РЕЗУЛЬТАТ] Дробная часть числа " << x << " равна "
              << Fraction(x) << '\n';

    return 0;
}