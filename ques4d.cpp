#include <iostream>
#include <cstring> // for strcmp, strcpy
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // clear newline from buffer

    char str[50][100]; // max 50 strings, each up to 99 chars

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin.getline(str[i], 100);
    }

    // Bubble sort for strings
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
