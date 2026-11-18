#include <iostream>
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

void generate_manual_array(int (&arr)[N]) {
    for (int i = 0; i < N; i++) {
        int number;
        std::cin >> number;
        arr[i] = number;
    }
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