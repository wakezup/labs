#include <iostream>

#include "input_utils.h"


int* FindAll(int* arr, const int length, int target, int& count) {
    count = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] == target) {
            ++count;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    int* indices = new int[count];
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] == target) {
            indices[index++] = i;
        }
    }
    return indices;
}

int main() {
    int length;
    int target;
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
    if (!(std::cin >> target) || !IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                  << '\n';
        delete[] arr;
        return 1;
    }
    int count;
    int* indices = FindAll(arr, length, target, count);
    if (indices == nullptr) {
        std::cout << "[РЕЗУЛЬТАТ] Число " << target
                  << " не найдено в массиве." << '\n';
    } else {
        std::cout << "[РЕЗУЛЬТАТ] Число " << target
                  << " найдено в массиве на позициях: ";
        for (int i = 0; i < count; ++i) {
            std::cout << indices[i];
            if (i < count - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "." << '\n';
        delete[] indices;
    }

    delete[] arr;
    return 0;
}