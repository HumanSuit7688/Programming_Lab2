#include <iostream>
#include <clocale>
#include <chrono>
#include <vector>
#include "array_utils.hpp"
#include "sorts.hpp"
#include "search_operations.hpp"

void sort_menu(int (&arr)[N]){
    int choice = -1;

    while (choice != 0) {
        int arr_copy[N];
        for (int i = 0; i < N; i++){
            arr_copy[i] = arr[i];
        }

        std::cout << "\n=== Сортировки ===\n"
                    << "1 - Bubble Sort\n"
                    << "2 - Insertion Sort\n"
                    << "3 - Selection Sort\n"
                    << "4 - Gnome Sort\n"
                    << "5 - Merge Sort\n"
                    << "0 - Выход\n\n";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введите номер пункта меню.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            const auto start = std::chrono::steady_clock::now();
            bubble_sort(arr_copy);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 2: {
            const auto start = std::chrono::steady_clock::now();
            insertion_sort(arr_copy);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 3: {
            const auto start = std::chrono::steady_clock::now();
            selection_sort(arr_copy);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 4: {
            const auto start = std::chrono::steady_clock::now();
            gnome_sort(arr_copy);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 5: {
            const auto start = std::chrono::steady_clock::now();
            merge_sort(arr_copy, 0, N-1);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 0:
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

void search_menu(int (&arr)[N]){
    int choice = -1;
    int arr_copy_sorted[N];
    for (int i = 0; i < N; i++){
            arr_copy_sorted[i] = arr[i];
        }
    insertion_sort(arr_copy_sorted);


    while(choice != 0) {
        std::cout << "\n=== Поиск ===\n"
                    << "1 - Максимальный элемент\n"
                    << "2 - Минимальный элемент\n"
                    << "3 - Среднее значение\n"
                    << "4 - Индексы элементов == среднему\n"
                    << "5 - Кол-во элементов < a\n"
                    << "6 - Кол-во элементов > b\n"
                    << "7 - Проверить наличие элемента\n"
                    << "0 - Выход\n\n";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введите номер пункта меню.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            auto start = std::chrono::steady_clock::now();
            int max = get_max_from_array(arr);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << "Неотсортированый массив: "<< elapsed.count() << " microseconds\n";

            start = std::chrono::steady_clock::now();
            max = arr_copy_sorted[N-1];
            end = std::chrono::steady_clock::now();
            elapsed = end - start;
            std::cout << "Отсортированый массив: "<< elapsed.count() << " microseconds\n";
            
            std::cout << "max = " << max << '\n';

            break;
        }
        case 2: {
            auto start = std::chrono::steady_clock::now();
            int min = get_min_from_array(arr);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << "Неотсортированый массив: "<< elapsed.count() << " microseconds\n";

            start = std::chrono::steady_clock::now();
            min = arr_copy_sorted[0];
            end = std::chrono::steady_clock::now();
            elapsed = end - start;
            std::cout << "Отсортированый массив: "<< elapsed.count() << " microseconds\n";
            
            std::cout << "min = " << min << '\n';

            break;
        }
        case 3: {
            const auto start = std::chrono::steady_clock::now();
            int average = get_average_min_max(arr);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;
            std::cout << "average = " << average << '\n';
            std::cout << elapsed.count() << " microseconds\n";
            break;
        }
        case 4: {
            int average = get_average_min_max(arr);

            const auto start = std::chrono::steady_clock::now();
            std::vector<int> indexes = get_elements_average(arr, average);
            const auto end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> elapsed = end - start;

            int amount = indexes.size();
            std::cout << "Неотсортированный массив: " << elapsed.count() << " microseconds\n";
            std::cout << "Всего " << amount << " элементов, равных среднему:\n";
            
            const auto sorted_start = std::chrono::steady_clock::now();
            std::vector<int> sorted_indexes = get_elements_average(arr_copy_sorted, average);
            const auto sorted_end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> sorted_elapsed = sorted_end - sorted_start;

            amount = sorted_indexes.size();
            std::cout << "Отсортированный массив: " << sorted_elapsed.count() << " microseconds\n";

            for (int index : indexes) {
                std::cout << index << ' ';
            }
            std::cout << '\n';
            break;
        }
        case 5: {
            int a;
            while (true) {
                std::cout << "Введите a: ";
                if (std::cin >> a) {
                    break;
                }
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка: введите корректное целое число.\n";
            }
            int amount_less = count_less_x(arr_copy_sorted, a);
            std::cout << amount_less << " элементов < " << a << '\n';
            break;
        }
        case 6: {
            int b;
            while (true) {
                std::cout << "Введите b: ";
                if (std::cin >> b) {
                    break;
                }
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка: введите корректное целое число.\n";
            }
            int amount_less = count_more_x(arr_copy_sorted, b);
            std::cout << amount_less << " элементов > " << b << '\n';
            break;
        }
        case 7: {
            int number;
             while (true) {
                std::cout << "Введите число: ";
                if (std::cin >> number) {
                    break;
                }
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка: введите корректное целое число.\n";
            }

            const auto linear_start = std::chrono::steady_clock::now();
            int index = linear_search(arr_copy_sorted, number);
            const auto linear_end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> linear_elapsed = linear_end - linear_start;
            std::cout << "Линейный поиск: " << linear_elapsed.count() << " microseconds\n";

            const auto binary_start = std::chrono::steady_clock::now();
            index = binary_search(arr_copy_sorted, number);
            const auto binary_end = std::chrono::steady_clock::now();
            const std::chrono::duration<double, std::micro> binary_elapsed = binary_end - binary_start;
            std::cout << "Бинарный поиск: " << binary_elapsed.count() << " microseconds\n";

            if (index != -1) {
                std::cout << "Елемент есть, на позиции " << index << '\n';
            }
            else {
                std::cout << "Елемента нет\n";
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << "Такого пункта меню нет\n";
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int arr[N]{};
    bool array_initialized = false;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n===== Главное меню =====\n"
                  << "1 - Заполнить массив случайными числами\n"
                  << "2 - Заполнить массив вручную\n"
                  << "3 - Вывести массив\n"
                  << "4 - Сортировка\n"
                  << "5 - Поиск\n"
                  << "6 - Поменять местами элементы\n"
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
            if (array_initialized) {
                sort_menu(arr);
            }
            else {
                std::cout << "Массив ещё не инициализирован\n";
            }
            break;
        case 5:
            if (array_initialized) {
                search_menu(arr);
            }
            else {
                std::cout << "Массив ещё не инициализирован\n";
            }
            break;
        case 6:
            if (array_initialized) {
                std::cout << "Введите два индекса через пробел:\n";
                int id1, id2;
                std::cin >> id1 >> id2;
                const auto start = std::chrono::steady_clock::now();
                std::swap(arr[id1], arr[id2]);
                const auto end = std::chrono::steady_clock::now();
                const std::chrono::duration<double, std::micro> elapsed = end - start;
                std::cout << elapsed.count() << " microseconds\n";   
            }
            else {
                std::cout << "Массив ещё не инициализирован\n";
            }
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
