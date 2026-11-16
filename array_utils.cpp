#include <iostream>
#include <random>
#include "array_utils.hpp"


void generate_random_array(int (&arr)[100], int l, int r) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(l, r);

    for (int i = 0; i < 100; i++) {
        int number = dist(gen);
        arr[i] = number;
    }

}

void generate_manual_array(int (&arr)[100]) {
    for (int i = 0; i < 100; i++) {
        int number;
        std::cin >> number;
        arr[i] = number;
    }
}