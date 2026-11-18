#pragma once

#include <vector>

#include "constants.hpp"

int get_min_from_array(const int (&arr)[N]);

int get_max_from_array(const int (&arr)[N]);

int get_average_min_max(const int (&arr)[N]);

std::vector<int> get_elements_average(
    const int (&arr)[N],
    int average
);

int count_less_x(
    const int (&arr)[N],
    int x
);

int count_more_x(
    const int (&arr)[N],
    int x
);

int binary_search(
    const int (&arr)[N],
    int target
);