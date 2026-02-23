#pragma once

template <class ItemType>
class DynamicQueue {
private:
    ItemType* items;
    int front;
    int rear;
    int count;
    int capacity;

public:
    DynamicQueue(int maxSize = 100);
    ~DynamicQueue();

    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
    ItemType Peek() const;
    int Size() const;
    int Capacity() const;

private:
    void Resize(int newCap);
};