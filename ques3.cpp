#include <iostream>
using namespace std;

int MissingIndexCheck(int arr[], int n) {
    int start = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] != start + i) {
            return start + i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout <<MissingIndexCheck(arr, n) << endl;

    return 0;
}

