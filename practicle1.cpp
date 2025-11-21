#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N;
    cout << "Enter number of terms: ";
    cin >> N;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < N; i++) {
        cout << fibonacci(i) << " ";
    }
    return 0;
}
