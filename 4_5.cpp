#include <iostream>

#include "input_utils.h"


int* Add(int* arr, int* ins, const int length, const int ins_length,
    int pos) {
    int* new_arr = new int[length + ins_length];
    for (int i = 0; i < pos; ++i) {
        new_arr[i] = arr[i];
    }
    for (int i = 0; i < ins_length; ++i) {
        new_arr[pos + i] = ins[i];
    }
    for (int i = pos; i < length; ++i) {
        new_arr[ins_length + i] = arr[i];
    }
    return new_arr;
}

int main() {
    int length;
    int ins_length;
    int pos;
    std::cout << "[ВВОД] Введите длину исходного массива: ";
    if (!(std::cin >> length) || !IsInputLineClean() || length <= 0) {
        std::cout << "[ОШИБКА] Введенное значение не является "
                     "положительным целым числом!"
                  << '\n';
        return 1;
    }
    int* arr = new int[length];
    std::cout << "[ВВОД] Введите " << length
              << " чисел для заполнения исходного массива (каждое число с "
                 "новой строки):\n";
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

    std::cout << "[ВВОД] Введите длину вставляемого массива: ";
    if (!(std::cin >> ins_length) || !IsInputLineClean() || ins_length <= 0) {
        std::cout << "[ОШИБКА] Введенное значение не является "
                     "положительным целым числом!"
                  << '\n';
        delete[] arr;
        return 1;
    }
    int* ins = new int[ins_length];
    std::cout << "[ВВОД] Введите " << ins_length
              << " чисел для заполнения вставляемого массива (каждое число "
                 "с новой строки):\n";
    for (int i = 0; i < ins_length; ++i) {
        if (!(std::cin >> ins[i])) {
            std::cout << "[ОШИБКА] Введенное значение не является целым числом!"
                      << '\n';
            delete[] arr;
            delete[] ins;
            return 1;
        }
    }
    if (!IsInputLineClean()) {
        std::cout << "[ОШИБКА] Введены лишние значения!" << '\n';
        delete[] arr;
        delete[] ins;
        return 1;
    }

    std::cout << "[ВВОД] Введите позицию для вставки: ";
    if (!(std::cin >> pos) || !IsInputLineClean() || pos < 0 ||
        pos > length) {
        std::cout << "[ОШИБКА] Введенное значение не является допустимой "
                     "позицией!"
                  << '\n';
        delete[] arr;
        delete[] ins;
        return 1;
    }
    int* new_arr = Add(arr, ins, length, ins_length, pos);
    std::cout << "[РЕЗУЛЬТАТ] Новый массив: ";
    for (int i = 0; i < length + ins_length; ++i) {
        std::cout << new_arr[i] << " ";
    }
    std::cout << '\n';

    delete[] new_arr;
    delete[] arr;
    delete[] ins;
    return 0;
}