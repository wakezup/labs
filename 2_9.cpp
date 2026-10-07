#include <iostream>
#include <string>

#include "input_utils.h"


std::string Day(int x) {
    switch (x) {
        case 1:
            return "Понедельник";
        case 2:
            return "Вторник";
        case 3:
            return "Среда";
        case 4:
            return "Четверг";
        case 5:
            return "Пятница";
        case 6:
            return "Суббота";
        case 7:
            return "Воскресенье";
        default:
            return "Это не день недели";
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

    std::cout << "[РЕЗУЛЬТАТ] " << Day(x) << '\n';

    return 0;
}
