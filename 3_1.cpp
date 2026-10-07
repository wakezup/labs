#include <iostream>
#include <string>

#include "input_utils.h"


std::string ListNums(int x) {
    std::string result;
    for (int i = 0; i <= x; ++i) {
        result += std::to_string(i);
        result += " ";
    }
    return result;
}

int main() {
    int x;

    std::cout << "[ВВОД] Введите целое число: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        return 1;
    }

    std::cout << "[РЕЗУЛЬТАТ] Список чисел от 0 до " << x << ": "
              << ListNums(x) << '\n';

    return 0;
}