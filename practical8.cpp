#include <iostream>
using namespace std;

int main() {
    int base, R, C, i, j, w;

    cout << "Enter base address: ";
    cin >> base;

    cout << "Enter number of rows and columns: ";
    cin >> R >> C;

    cout << "Enter element position (i j): ";
    cin >> i >> j;

    cout << "Enter size of each element in bytes: ";
    cin >> w;

    // Row-major: A[i][j]
    int rowMajor = base + ( (i * C) + j ) * w;

    // Column-major: A[i][j]
    int colMajor = base + ( (j * R) + i ) * w;

    cout << "\nAddress in Row-Major Order: " << rowMajor;
    cout << "\nAddress in Column-Major Order: " << colMajor;

    return 0;
}
