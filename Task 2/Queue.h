#pragma once

class Queue {
private:
    int* items;
    int front;
    int rear;
    int count;
    int capacity;

public:
    Queue(int maxSize = 100);
    ~Queue();

    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(int item);
    void Dequeue(int& item);
    int Peek() const;
    int Size() const;

    void ReverseK(int k);
};