#include <iostream>

#include "input_utils.h"


int FindFirst(int* arr, const int length, int x) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int x;
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

    std::cout << "[ВВОД] Введите число для поиска в массиве: ";
    if (!(std::cin >> x) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        delete[] arr;
        return 1;
    }
    int index = FindFirst(arr, length, x);
    if (index != -1) {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x
                  << " найдено в массиве на позиции " << index << "." << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Число " << x << " не найдено в массиве."
                  << '\n';
    }

    delete[] arr;
    return 0;
}