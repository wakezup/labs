#include <iostream>

#include "input_utils.h"


int NumLen(long x) {
    if (x == 0) {
        return 1;
    }
    int length = 0;
    while (x != 0) {
        x /= 10;
        ++length;
    }
    return length;
}

int main() {
    long x;

    std::cout << "[ВВОД] Введите целое число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }

    std::cout << "[РЕЗУЛЬТАТ] Количество цифр в числе " << x << " равно "
              << NumLen(x) << "." << '\n';

    return 0;
}