#include <iostream>
#include "array_utils.hpp"
#include "sorts.hpp"

void sort_menu(int (&arr)[N]){
    int choice = -1;

    while (choice != 0) {
        int arr_copy[N];
        for (int i = 0; i < N; i++){
            arr_copy[i] = arr[i];
        }

        std::cout << "=== Сортировки ===\n"
                    << "1 - Buble Sort\n"
                    << "2 - Insertion Sort\n"
                    << "3 - Selection Sort\n"
                    << "4 - Gnome Sort\n"
                    << "5 - Merge Sort\n"
                    << "0 - Выход\n";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введите номер пункта меню.\n";
            continue;
        }

        switch (choice) {
        case 1:
            bubble_sort(arr_copy);
            break;
        case 2:
            insertion_sort(arr_copy);
            break;
        case 3:
            selection_sort(arr_copy);
            break;
        case 4:
            gnome_sort(arr_copy);
            break;
        case 5:
            merge_sort(arr_copy, 0, N-1);
            break;
        default:
            std::cout << "Такого пункта меню нет\n";
            break;
        }

        if (choice >= 1 && choice <= 5){
            std::cout << "Отсортированный массив:\n";
            output_array(arr_copy);
        }
    }

}

int main() {
    int arr[N]{};
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
        
        case 4:
            sort_menu(arr);
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
