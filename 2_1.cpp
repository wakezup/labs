#include <iostream>

#include "input_utils.h"


int Abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main() {
    int x;

    std::cout << "[ВВОД] Введите целое число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }

    std::cout << "[РЕЗУЛЬТАТ] Модуль числа " << x << " равен " << Abs(x)
              << '\n';

    return 0;
}