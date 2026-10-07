#include <iostream>

#include "input_utils.h"


bool IsInRange(int a, int b, int number) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    return number >= a && number <= b;
}

int main() {
    int a;
    int b;
    int number;

    std::cout << "[ВВОД] Введите два числа (a и b): ";
    if (!(std::cin >> a >> b) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенные значения не являются целыми числами!"
                  << '\n';
        return 1;
    }
    std::cout << "[ВВОД] Введите число для проверки: ";
    if (!(std::cin >> number) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }
    if (IsInRange(a, b, number)) {
        std::cout << "[РЕЗУЛЬТАТ] Число " << number
                  << " находится в диапазоне от "
                  << a << " до " << b << "." << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Число " << number
                  << " не находится в диапазоне от " << a << " до " << b
                  << "." << '\n';
    }

    return 0;
}