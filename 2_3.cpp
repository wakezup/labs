#include <iostream>

#include "input_utils.h"


bool Is35(int x) {
    if (x % 3 == 0 || x % 5 == 0) {
        if (x % 3 == 0 && x % 5 == 0) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int x;

    std::cout << "[ВВОД] Введите целое число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }

    if (Is35(x)) {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x
                  << " делится на 3 или на 5, но не на оба." << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x
                  << " не делится на 3 или на 5, либо делится на оба."
                  << '\n';
    }

    return 0;
}