#include <iostream>

#include "input_utils.h"


bool IsEqual(int a, int b, int c) {
    return a == b && b == c;
}

int main() {
    int a;
    int b;
    int c;

    std::cout << "[ВВОД] Введите три числа: ";
    if (!(std::cin >> a >> b >> c) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенные значения не являются целыми числами!"
                  << '\n';
        return 1;
    }
    if (IsEqual(a, b, c)) {
        std::cout << "[РЕЗУЛЬТАТ] Все три числа равны." << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Числа не равны." << '\n';
    }

    return 0;
}