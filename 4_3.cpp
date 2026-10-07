#include <iostream>

#include "input_utils.h"


int MaxAbs(int* arr, const int length) {
    int max_abs_value = arr[0];
    if (max_abs_value < 0) {
        max_abs_value = -max_abs_value;
    }

    for (int i = 1; i < length; ++i) {
        int current_abs = arr[i];
        if (current_abs < 0) {
            current_abs = -current_abs;
        }
        if (current_abs > max_abs_value) {
            max_abs_value = current_abs;
        }
    }
    return max_abs_value;
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

    int max_abs_value = MaxAbs(arr, length);
    std::cout << "[РЕЗУЛЬТАТ] Максимальное по модулю число в массиве равно "
              << max_abs_value << "." << '\n';

    delete[] arr;
    return 0;
}