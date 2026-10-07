#include <iostream>

#include "input_utils.h"


int Max3(int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    } else if (y >= x && y >= z) {
        return y;
    } else {
        return z;
    }
}

int main() {
    int x;
    int y;
    int z;

    std::cout << "[ВВОД] Введите три целых числа: ";
    if (!(std::cin >> x >> y >> z) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенные значения не являются целыми числами!"
                  << '\n';
        return 1;
    }

    int max_value = Max3(x, y, z);
    std::cout << "[РЕЗУЛЬТАТ] Максимальное число из " << x << ", " << y
              << " и " << z << " равно " << max_value << "." << '\n';

    return 0;
}