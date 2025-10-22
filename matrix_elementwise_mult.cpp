#include <iostream>
using namespace std;

int main() {
    int A[2][4], B[2][4], C[2][4];

    cout << "Enter elements of first 2x4 matrix (row-wise):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> A[i][j];

    cout << "Enter elements of second 2x4 matrix (row-wise):\n";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> B[i][j];

    // Element-wise multiplication
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 4; ++j)
            C[i][j] = A[i][j] * B[i][j];

    cout << "Result of element-wise multiplication:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}