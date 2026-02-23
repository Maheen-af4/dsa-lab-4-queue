#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    cout << "Input:\n";

    int n, k;
    cin >> n >> k;

// Error handling
if (n < 0) {
    cout << "Error: n must be a positive number.\n";
    return 0;
}if (n == 0) {
    cout << "Error: n cannot be zero.\n";
    return 0;
}
if (k <= 0) {
    cout << "Error: k must be a positive number.\n";
    return 0;
}
if (k > n) {
    cout << "Error: k cannot be greater than n.\n";
    return 0;
}

    Queue q(n);
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        q.Enqueue(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";

    q.ReverseK(k);

    cout << "Output:\n";

    int x;
    int* result = new int[n];
    int idx = 0;

    while (!q.IsEmpty()) {
        q.Dequeue(x);
        result[idx++] = x;
        cout << x << " ";
    }

    cout << "\n\nExplanation:\n";
    cout << "After reversing the given input from the " 
         << k << "rd position the resultant output will be ";

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    cout << endl;

    delete[] arr;
    delete[] result;

    return 0;
}