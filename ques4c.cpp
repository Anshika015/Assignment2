#include <iostream>
using namespace std;

int main() {
    char str[100];
    char result[100];
    int i = 0, j = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    while (str[i] != '\0') {
        char ch = str[i];
        // Check if character is NOT a vowel
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            result[j] = ch;
            j++;
        }
        i++;
    }
    result[j] = '\0'; // Null terminate

    cout << "String without vowels: " << result << endl;

    return 0;
}
