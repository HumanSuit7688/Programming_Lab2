#include <iostream>
#include "search_operations.hpp"
#include "individual_task.hpp"

int count_inverse_simple_enumeration(const int (&arr)[N]){
    int amount_inverse = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                amount_inverse++;
            }
        }
    }
    return amount_inverse;
}


int merge_inverse(int (&arr)[N], int l, int mid, int r) {
    int amount_inverse = 0;
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
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            amount_inverse += (n1 - i);
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
    return amount_inverse;
}


int merge_sort_inverse(int (&arr)[N], int l, int r) {
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;
    
    int amount_inverse = (merge_sort_inverse(arr, l, mid) + merge_sort_inverse(arr, mid + 1, r));
    
    amount_inverse += merge_inverse(arr, l, mid, r);
    return amount_inverse;
}


