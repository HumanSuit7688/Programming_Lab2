#pragma once

#include "constants.hpp"

void bubble_sort(int (&arr)[N]);

void insertion_sort(int (&arr)[N]);

void selection_sort(int (&arr)[N]);

void gnome_sort(int (&arr)[N]);

void merge(
    int (&arr)[N],
    int l,
    int mid,
    int r
);

void merge_sort(
    int (&arr)[N],
    int l,
    int r
);