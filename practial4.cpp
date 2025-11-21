#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBubble Sort Passes:\n";

    for (int i = 0; i < n - 1; i++) {
        cout << "Pass " << i + 1 << ": ";

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }

        // Print array after each pass
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
