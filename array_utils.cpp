#include <iostream>
#include <limits>
#include <random>
#include <utility>
#include "array_utils.hpp"


void generate_random_array(int (&arr)[N], int l, int r) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(l, r);

    for (int i = 0; i < N; i++) {
        int number = dist(gen);
        arr[i] = number;
    }

}

bool generate_manual_array(int (&arr)[N]) {
    int input[N];
    for (int i = 0; i < N; i++) {
        int number;
        while (!(std::cin >> number)) {
            if (std::cin.eof()) {
                return false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое число для элемента " << i << ".\n";
        }
        input[i] = number;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = input[i];
    }
    return true;
}

void output_array(const int (&arr)[N]) {
    for (int element : arr) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

void swap_elevents(int (&arr)[N], int id1, int id2) {
    std::swap(arr[id1], arr[id2]);
}
