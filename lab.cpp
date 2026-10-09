#include <iostream>
#include <string>

#include "input_utils.h"

double Fraction(double x) {
    int integer_part = static_cast<int>(x);
    return x - integer_part;
}

int CharToNum(char x) {
    return static_cast<int>(x) - static_cast<int>('0');
}

bool Is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x >= -99 && x <= -10);
}

bool IsInRange(int a, int b, int number) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    return number >= a && number <= b;
}

bool IsEqual(int a, int b, int c) {
    return a == b && b == c;
}

int Abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

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

int Max3(int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    } else if (y >= x && y >= z) {
        return y;
    } else {
        return z;
    }
}

int Sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    } else {
        return sum;
    }
}

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

std::string ListNums(int x) {
    std::string result;
    for (int i = 0; i <= x; ++i) {
        result += std::to_string(i);
        result += " ";
    }
    return result;
}

std::string Chet(int x) {
    std::string result;
    for (int i = 0; i <= x; i += 2) {
        result += std::to_string(i);
        result += " ";
    }
    return result;
}

int NumLen(long x) {
    if (x == 0) {
        return 1;
    }
    int length = 0;
    while (x != 0) {
        x /= 10;
        ++length;
    }
    return length;
}

void Square(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

void RightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x - i; ++j) {
            std::cout << "  ";
        }
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
}

int FindFirst(int* arr, const int length, int x) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

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

int* ReverseBack(int* arr, const int length) {
    int* reversed_arr = new int[length];
    for (int i = 0; i < length; ++i) {
        reversed_arr[i] = arr[length - 1 - i];
    }
    return reversed_arr;
}

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
    int task;
    std::cout << "[ВВОД] Введите номер задания: ";
    std::cin >> task;

    switch(task) {
        case 11: {
            double x;

            std::cout << "[ВВОД] Введите число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение "
                             " не является числом!"
                          << '\n';
                return 1;
            }
            std::cout << "[РЕЗУЛЬТАТ] Дробная часть числа " 
                      << x << " равна "
                      << Fraction(x) << '\n';

            return 0;

        } case 13: {
            char x;

            std::cout << "[ВВОД] Введите цифру: ";
            if (!(std::cin >> x) || !IsInputLineClean()
                || x < '0' || x > '9') {
                std::cout << "[ОШИБКА] Введенное значение не является цифрой!"
                          << '\n';
                return 1;
            }
            std::cout << "[РЕЗУЛЬТАТ] Цифра " << x << " соответствует числу "
                      << CharToNum(x) << '\n';

            return 0;

        } case 15: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            if (Is2Digits(x)) {
                std::cout << "[РЕЗУЛЬТАТ] Число " << x
                          << " является двузначным." << '\n';
            } else {
                std::cout << "[РЕЗУЛЬТАТ] Число " << x
                          << " не является двузначным." << '\n';
            }

            return 0;

        } case 17: {
            int a;
            int b;
            int number;

            std::cout << "[ВВОД] Введите два числа (a и b): ";
            if (!(std::cin >> a >> b) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенные значения"
                             "не являются целыми числами!" << '\n';
                return 1;
            }
            std::cout << "[ВВОД] Введите число для проверки: ";
            if (!(std::cin >> number) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             "не является целым числом!" << '\n';
                return 1;
            }
            if (IsInRange(a, b, number)) {
                std::cout << "[РЕЗУЛЬТАТ] Число " << number
                          << " находится в диапазоне от "
                          << a << " до " << b << "." << '\n';
            } else {
                std::cout << "[РЕЗУЛЬТАТ] Число " << number
                          << " не находится в диапазоне от "
                          << a << " до " << b << "." << '\n';
            }

            return 0;

        } case 19: {
            int a;
            int b;
            int c;

            std::cout << "[ВВОД] Введите три числа: ";
            if (!(std::cin >> a >> b >> c) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенные значения"
                             " не являются целыми числами!" << '\n';
                return 1;
            }
            if (IsEqual(a, b, c)) {
                std::cout << "[РЕЗУЛЬТАТ] Все три числа равны." << '\n';
            } else {
                std::cout << "[РЕЗУЛЬТАТ] Числа не равны." << '\n';
            }

            return 0;

        } case 21: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Модуль числа "
                      << x << " равен " << Abs(x) << '\n';

            return 0;

        } case 23: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
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

        } case 25: {
            int x;
            int y;
            int z;

            std::cout << "[ВВОД] Введите три целых числа: ";
            if (!(std::cin >> x >> y >> z) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенные значения"
                             " не являются целыми числами!" << '\n';
                return 1;
            }

            int max_value = Max3(x, y, z);
            std::cout << "[РЕЗУЛЬТАТ] Максимальное число из " << x << ", " << y
                      << " и " << z << " равно " << max_value << "." << '\n';

            return 0;

        } case 27: {
            int x;
            int y;

            std::cout << "[ВВОД] Введите два целых числа: ";
            if (!(std::cin >> x >> y) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенные значения"
                             " не являются целыми числами!" << '\n';
                return 1;
            }

            int result = Sum2(x, y);
            std::cout << "[РЕЗУЛЬТАТ] Результат функции sum2("
                      << x << ", " << y << ") равен " << result << "." << '\n';

            return 0;

        } case 29: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] " << Day(x) << '\n';

            return 0;

        } case 31: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Список чисел от 0 до " << x << ": "
                    << ListNums(x) << '\n';

            return 0;

        } case 33: {
            int x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Четные числа от 0 до "
                      << x << ": " << Chet(x) << '\n';

            return 0;

        } case 35: {
            long x;

            std::cout << "[ВВОД] Введите целое число: ";
            if (!(std::cin >> x) || !IsInputLineClean()) {
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Количество цифр в числе "
                      << x << " равно " << NumLen(x) << "." << '\n';

            return 0;

        } case 37: {
            int x;

            std::cout << "[ВВОД] Введите целое положительное число: ";
            if (!(std::cin >> x) || !IsInputLineClean() || x <= 0) {
                std::cout << "[ОШИБКА] Введенное значение не является целым "
                             "положительным числом!"
                          << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Квадрат из " << x << " строк и " << x
                      << " столбцов:" << '\n';
            Square(x);

            return 0;

        } case 39: {
            int x;

            std::cout << "[ВВОД] Введите целое положительное число: ";
            if (!(std::cin >> x) || !IsInputLineClean() || x <= 0) {
                std::cout << "[ОШИБКА] Введенное значение не является целым "
                             "положительным числом!"
                          << '\n';
                return 1;
            }

            std::cout << "[РЕЗУЛЬТАТ] Прямоугольный треугольник с " << x
                      << " строками:" << '\n';
            RightTriangle(x);

            return 0;

        } case 41: {
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
                    std::cout << "[ОШИБКА] Введенное значение"
                                 " не является целым числом!" << '\n';
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
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
                delete[] arr;
                return 1;
            }
            int index = FindFirst(arr, length, x);
            if (index != -1) {
                std::cout << "[РЕЗУЛЬТАТ] Число " << x
                          << " найдено в массиве на позиции "
                          << index << "." << '\n';
            } else {
                std::cout << "[РЕЗУЛЬТАТ] Число " << x
                          << " не найдено в массиве." << '\n';
            }

            delete[] arr;
            return 0;

        } case 43: {
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
                    std::cout << "[ОШИБКА] Введенное значение"
                                 " не является целым числом!" << '\n';
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
            std::cout << "[РЕЗУЛЬТАТ] Максимальное по модулю"
                         " число в массиве равно " << max_abs_value
                      << "." << '\n';

            delete[] arr;
            return 0;

        } case 45: {
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
                      << " чисел для заполнения исходного массива"
                         "(каждое число с новой строки):\n";
            for (int i = 0; i < length; ++i) {
                if (!(std::cin >> arr[i])) {
                    std::cout << "[ОШИБКА] Введенное значение"
                                 " не является целым числом!"
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
            if (!(std::cin >> ins_length) || !IsInputLineClean()
                || ins_length <= 0) {
                std::cout << "[ОШИБКА] Введенное значение не является "
                            "положительным целым числом!"
                          << '\n';
                delete[] arr;
                return 1;
            }
            int* ins = new int[ins_length];
            std::cout << "[ВВОД] Введите " << ins_length
                      << " чисел для заполнения вставляемого массива"
                       "(каждое число с новой строки):\n";
            for (int i = 0; i < ins_length; ++i) {
                if (!(std::cin >> ins[i])) {
                    std::cout << "[ОШИБКА] Введенное значение"
                                 " не является целым числом!" << '\n';
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
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является допустимой позицией!" << '\n';
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

        } case 47: {
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
                    std::cout << "[ОШИБКА] Введенное значение"
                                 " не является целым числом!" << '\n';
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

        } case 49: {
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
                    std::cout << "[ОШИБКА] Введенное значение" 
                                 " не является целым числом!" << '\n';
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
                std::cout << "[ОШИБКА] Введенное значение"
                             " не является целым числом!" << '\n';
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
        } default:
            std::cout << "[ОШИБКА] Некорректный номер задания" << std::endl;
            return 1;
    }
}