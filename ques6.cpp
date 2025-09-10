#include <iostream>
using namespace std;

int main() {
    int r1, c1, t1;
    cout << "Enter rows, columns, no of elements of first matrix: ";
    cin >> r1 >> c1 >> t1;

    int mat1[100][3];
    cout << "Enter row, column,value of each element of first matrix:" << endl;
    for (int i = 0; i < t1; i++) {
        cin >> mat1[i][0] >> mat1[i][1] >> mat1[i][2];
    }

    int r2, c2, t2;
    cout << "Enter rows, columns, and no of elements of second matrix: ";
    cin >> r2 >> c2 >> t2;

    int mat2[100][3];
    cout << "Enter row, column,value of each element of second matrix:" << endl;
    for (int i = 0; i < t2; i++) {
        cin >> mat2[i][0] >> mat2[i][1] >> mat2[i][2];
    }

    // Transpose of first matrix 
    cout << "\nTranspose of first matrix:" << endl;
    int trans[100][3];
    for (int i = 0; i < t1; i++) {
        trans[i][0] = mat1[i][1]; 
        trans[i][1] = mat1[i][0];
        trans[i][2] = mat1[i][2];
    }

    for (int i = 0; i < t1; i++) {
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
    }

    // Addition of two matrices
    if (r1 != r2 || c1 != c2) {
        cout << "\nAddition not possible due to dimension mismatch." << endl;
    } else {
        cout << "\nAddition of two matrices:" << endl;
        int result[200][3]; 
        int i = 0, j = 0, k = 0;

        while (i < t1 && j < t2) {
            if (mat1[i][0] < mat2[j][0] || 
                (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
                result[k][0] = mat1[i][0];
                result[k][1] = mat1[i][1];
                result[k][2] = mat1[i][2];
                i++; k++;
            } else if (mat1[i][0] > mat2[j][0] || 
                       (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1])) {
                result[k][0] = mat2[j][0];
                result[k][1] = mat2[j][1];
                result[k][2] = mat2[j][2];
                j++; k++;
            } else {
                result[k][0] = mat1[i][0];
                result[k][1] = mat1[i][1];
                result[k][2] = mat1[i][2] + mat2[j][2];
                i++; j++; k++;
            }
        }

        while (i < t1) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++; k++;
        }

        while (j < t2) {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++; k++;
        }

        for (int idx = 0; idx < k; idx++) {
            cout << result[idx][0] << " " << result[idx][1] << " " << result[idx][2] << endl;
        }
    }

    // Multiplication of two matrices
    if (c1 != r2) {
        cout << "\nMultiplication not possible due to dimension mismatch." << endl;
    } else {
        cout << "\nMultiplication of two matrices:" << endl;
        int mult[100][3];
        int count = 0;

        for (int i = 0; i< t1; i++) {
            for (int j = 0; j < t2; j++) {
                if (mat1[i][1] == mat2[j][0]) {
                    int r = mat1[i][0];
                    int c = mat2[j][1];
                    int val = mat1[i][2] * mat2[j][2];
                    int found = 0;
                    for (int k = 0; k < count; k++) {
                        if (mult[k][0] == r && mult[k][1] == c) {
                            mult[k][2] += val;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        mult[count][0] = r;
                        mult[count][1] = c;
                        mult[count][2] = val;
                        count++;
                    }
                }
            }
        }

        for (int idx = 0; idx < count; idx++) {
            cout << mult[idx][0] << " " << mult[idx][1] << " " << mult[idx][2] << endl;
        }
    }

    return 0;
}

