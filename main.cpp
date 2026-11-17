#include <iostream>
#include "array_utils.hpp"

int main() {
    int arr[100]{};
    bool array_initialized = false;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n===== Главное меню =====\n"
                  << "1 - Заполнить массив случайными числами\n"
                  << "2 - Заполнить массив вручную\n"
                  << "3 - Вывести массив\n"
                  << "4 - Сортировка\n"
                  << "0 - Выйти\n"
                  << "Выберите пункт: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введите номер пункта меню.\n";
            continue;
        }

        switch (choice) {
        case 1:
            generate_random_array(arr, -99, 99);
            array_initialized = true;
            std::cout << "Массив заполнен случайными числами.\n";
            break;

        case 2:
            std::cout << "Введите 100 целых чисел:\n";
            generate_manual_array(arr);
            array_initialized = true;
            std::cout << "Массив заполнен вручную.\n";
            break;

        case 3:
            if (!array_initialized) {
                std::cout << "Сначала заполните массив.\n";
                break;
            }

            std::cout << "Текущий массив:\n";
            output_array(arr);
            break;

        case 0:
            std::cout << "Выход.\n";
            break;

        default:
            std::cout << "Такого пункта меню нет.\n";
            break;
        }
    }

    return 0;
}
