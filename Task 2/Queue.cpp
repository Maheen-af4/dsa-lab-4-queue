#include "Queue.h"

Queue::Queue(int maxSize) {
    capacity = maxSize;
    items = new int[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] items;
}

bool Queue::IsEmpty() const { return count == 0; }
bool Queue::IsFull() const { return count == capacity; }

void Queue::Enqueue(int item) {
    if (IsFull()) return;
    rear = (rear + 1) % capacity;
    items[rear] = item;
    count++;
}

void Queue::Dequeue(int& item) {
    if (IsEmpty()) return;
    item = items[front];
    front = (front + 1) % capacity;
    count--;
}

int Queue::Peek() const {
    if (IsEmpty()) return -1;
    return items[front];
}

int Queue::Size() const { return count; }

void Queue::ReverseK(int k) {
    if (k <= 0 || k > count) return;

    int* temp = new int[k];

    for (int i = 0; i < k; i++)
        temp[i] = items[(front + i) % capacity];

    for (int i = 0; i < k / 2; i++) {
        int t = temp[i];
        temp[i] = temp[k - 1 - i];
        temp[k - 1 - i] = t;
    }

    for (int i = 0; i < k; i++)
        items[(front + i) % capacity] = temp[i];

    delete[] temp;
}