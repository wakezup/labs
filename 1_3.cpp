#include <iostream>

#include "input_utils.h"

int CharToNum(char x) {
    return static_cast<int>(x) - static_cast<int>('0');
}

int main() {
    char x;

    std::cout << "[ВВОД] Введите цифру: ";
    if (!(std::cin >> x) || !IsInputLineClean() || x < '0' || x > '9') {
        std::cout << "[ОШИБКА] Введенное значение не является цифрой!" << '\n';
        return 1;
    }
    std::cout << "[РЕЗУЛЬТАТ] Цифра " << x << " соответствует числу "
              << CharToNum(x) << '\n';

    return 0;
}