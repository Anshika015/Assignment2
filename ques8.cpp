#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[100];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j])
                break;  
        }
        if (j == i) 
            count++;
    }

    cout << "Number of distinct elements: " << count << endl;

    return 0;
}


