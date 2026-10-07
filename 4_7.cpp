#include <iostream>

#include "input_utils.h"


int* ReverseBack(int* arr, const int length) {
    int* reversed_arr = new int[length];
    for (int i = 0; i < length; ++i) {
        reversed_arr[i] = arr[length - 1 - i];
    }
    return reversed_arr;
}

int main() {
    int length;
    std::cout << "[ВВОД] Введите длину массива: ";
    if (!(std::cin >> length) || !IsInputLineClean() || length <= 0) {
        std::cout << "[ОШИБКА] Введенное значение не является "
                     "положительным целым числом!"
                  << '\n';
        return 1;
    }
    int* arr = new int[length];
    std::cout << "[ВВОД] Введите " << length
              << " чисел для заполнения массива (каждое число с новой "
                 "строки):\n";
    for (int i = 0; i < length; ++i) {
        if (!(std::cin >> arr[i])) {
            std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                      << '\n';
            delete[] arr;
            return 1;
        }
    }
    if (!IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введены лишние значения!" << '\n';
        delete[] arr;
        return 1;
    }

    int* reversed_arr = ReverseBack(arr, length);
    std::cout << "[РЕЗУЛЬТАТ] Перевернутый массив: ";
    for (int i = 0; i < length; ++i) {
        std::cout << reversed_arr[i];
        if (i < length - 1) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';

    delete[] reversed_arr;
    delete[] arr;
    return 0;
}