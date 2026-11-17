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


void merge(int (&arr)[N], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[N], R[N];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int (&arr)[N], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}