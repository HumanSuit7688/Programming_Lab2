#include <utility>

#include "sorts.hpp"

void bubble_sort(int (&arr)[N]) {
    int n = N;
    bool swapped = false;
    for (int i = 0; i < n; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

    }
}


void insertion_sort(int (&arr)[N]) {
    int n = N;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void selection_sort(int (&arr)[N]) {
    int n = N;

    for (int i = 0; i < n; i++) {
        int min_id = i;
        for (int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_id]) {
                min_id = j;
            }
        }

        if (min_id != i) {
            std::swap(arr[i], arr[min_id]);
        }
    }
}


void gnome_sort(int (&arr)[N]) {
    int n = N;
    int i = 0;

    while(i < n) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            i++;
        }
        else {
            std::swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}
