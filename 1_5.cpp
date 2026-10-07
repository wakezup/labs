#include <iostream>

#include "input_utils.h"


bool Is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x >= -99 && x <= -10);
}

int main() {
    int x;

    std::cout << "[ВВОД] Введите целое число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }

    if (Is2Digits(x)) {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x << " является двузначным."
                  << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x
                  << " не является двузначным." << '\n';
    }

    return 0;
}