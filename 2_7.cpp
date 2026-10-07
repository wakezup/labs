#include <iostream>

#include "input_utils.h"


int Sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    } else {
        return sum;
    }
}

int main() {
    int x;
    int y;

    std::cout << "[ВВОД] Введите два целых числа: ";
    if (!(std::cin >> x >> y) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенные значения не являются целыми числами!"
                  << '\n';
        return 1;
    }

    int result = Sum2(x, y);
    std::cout << "[РЕЗУЛЬТАТ] Результат функции sum2(" << x << ", " << y
              << ") равен " << result << "." << '\n';

    return 0;
}