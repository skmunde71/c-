#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 2) {
        cout << "A Fibonacci sequence needs at least 2 elements." << endl;
        return 1;
    }

    vector<int> cabbage(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> cabbage[i];
    }

    bool isFibonacci = true;
    for (int i = 2; i < n; ++i) {
        if (cabbage[i] != cabbage[i-1] + cabbage[i-2]) {
            isFibonacci = false;
            break;
        }
    }

    if (isFibonacci) {
        cout << "The sequence follows the Fibonacci rule." << endl;
    } else {
        cout << "The sequence does NOT follow the Fibonacci rule." << endl;
    }

    return 0;
}