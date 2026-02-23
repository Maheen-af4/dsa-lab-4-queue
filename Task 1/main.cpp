#include <iostream>
#include "DynamicQueue.h"
using namespace std;

int main() {
    DynamicQueue<int> q(5);

    for (int i = 1; i <= 10; i++) q.Enqueue(i);
    cout << "Size: " << q.Size() << " Capacity: " << q.Capacity() << endl;

    int x;
    for (int i = 0; i < 5; i++) {
        q.Dequeue(x);
        cout << "Dequeued: " << x << endl;
    }

    cout << "Front: " << q.Peek() << endl;
    cout << "Size: " << q.Size() << endl;

    return 0;
}