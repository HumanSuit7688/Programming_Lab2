#include <cmath>
#include <vector>

#include "search_operations.hpp"

int get_min_from_array(const int (&arr)[N]) {
    int minimum = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int get_max_from_array(const int (&arr)[N]) {
    int maximum = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

int get_average_min_max(const int (&arr)[N]) {
    const int maximum = get_max_from_array(arr);
    const int minimum = get_min_from_array(arr);
    const double average = (minimum + maximum) / 2.0;

    return static_cast<int>(std::round(average));
}

std::vector<int> get_elements_average(const int (&arr)[N], int average) {
    int amount = 0;

    for (int i = 0; i < N; i++){
        if (arr[i] == average) {
            amount++;
        }
    }

    std::vector<int> elements_indexes;
    elements_indexes.reserve(amount);

    for (int i = 0; i < N; i++){
        if (arr[i] == average) {
            elements_indexes.push_back(i);
        }
    }

    return elements_indexes;
}

