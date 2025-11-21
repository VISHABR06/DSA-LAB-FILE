#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1)
        return 1;   // Base case: 0! = 1, 1! = 1
    return n * factorial(n - 1);  // Recursive step
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial of a negative number doesn't exist.";
    } else {
        cout << "Factorial of " << n << " is: " << factorial(n);
    }

    return 0;
}
