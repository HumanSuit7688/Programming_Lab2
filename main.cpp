#include <iostream>
#include "array_utils.hpp"
using namespace std;

int main() {
    int arr[100];
    generate_random_array(arr, -99, 99);
    for (int i = 0; i < 100; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}