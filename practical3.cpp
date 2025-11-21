#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, pos, value;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    do {
        cin >> choice;

        if (choice == 1) {             // Insert
            cin >> pos >> value;
            for (int i = n; i >= pos; i--) arr[i] = arr[i - 1];
            arr[pos - 1] = value;
            n++;
        }
        else if (choice == 2) {        // Delete
            cin >> pos;
            for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
        }
        else if (choice == 3) {        // Traverse
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }

    } while (choice != 4);

    return 0;
}
