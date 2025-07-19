#include <iostream>
using namespace std;

int main() {
    const int D1 = 2, D2 = 2, D3 = 2, D4 = 2;
    int A[D1][D2][D3][D4], B[D1][D2][D3][D4], C[D1][D2][D3][D4];

    cout << "Enter elements of first 2x2x2x2 matrix:\n";
    for (int i = 0; i < D1; ++i)
        for (int j = 0; j < D2; ++j)
            for (int k = 0; k < D3; ++k)
                for (int l = 0; l < D4; ++l)
                    cin >> A[i][j][k][l];

    cout << "Enter elements of second 2x2x2x2 matrix:\n";
    for (int i = 0; i < D1; ++i)
        for (int j = 0; j < D2; ++j)
            for (int k = 0; k < D3; ++k)
                for (int l = 0; l < D4; ++l)
                    cin >> B[i][j][k][l];

    // Element-wise multiplication
    for (int i = 0; i < D1; ++i)
        for (int j = 0; j < D2; ++j)
            for (int k = 0; k < D3; ++k)
                for (int l = 0; l < D4; ++l)
                    C[i][j][k][l] = A[i][j][k][l] * B[i][j][k][l];

    cout << "Result of element-wise multiplication:\n";
    for (int i = 0; i < D1; ++i)
        for (int j = 0; j < D2; ++j)
            for (int k = 0; k < D3; ++k)
                for (int l = 0; l < D4; ++l)
                    cout << "C[" << i << "][" << j << "][" << k << "][" << l << "] = "
                         << C[i][j][k][l] << endl;

    return 0;
}