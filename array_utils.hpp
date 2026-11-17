#pragma once

#include "constants.hpp"

void generate_random_array(
    int (&arr)[N],
    int l, 
    int r
);

void generate_manual_array(
    int (&arr)[N]
);

void output_array(
    const int (&arr)[N]
);
