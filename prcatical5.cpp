#include <iostream>
using namespace std;

int main() {
    int n, key;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> key;

    int low = 0, high = n - 1, mid, found = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) { found = mid; break; }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << found;
    return 0;
}
