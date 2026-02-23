#include "DynamicQueue.h"
#include <string>   

template <class ItemType>
DynamicQueue<ItemType>::DynamicQueue(int maxSize) {
    capacity = maxSize;
    items = new ItemType[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

template <class ItemType>
DynamicQueue<ItemType>::~DynamicQueue() {
    delete[] items;
}

template <class ItemType>
bool DynamicQueue<ItemType>::IsEmpty() const { return count == 0; }

template <class ItemType>
bool DynamicQueue<ItemType>::IsFull() const { return count == capacity; }

template <class ItemType>
void DynamicQueue<ItemType>::Enqueue(ItemType item) {
    if (IsFull()) Resize(capacity * 2);
    rear = (rear + 1) % capacity;
    items[rear] = item;
    count++;
}

template <class ItemType>
void DynamicQueue<ItemType>::Dequeue(ItemType& item) {
    if (IsEmpty()) return;
    item = items[front];
    front = (front + 1) % capacity;
    count--;
}

template <class ItemType>
ItemType DynamicQueue<ItemType>::Peek() const {
    if (IsEmpty()) return ItemType();
    return items[front];
}

template <class ItemType>
int DynamicQueue<ItemType>::Size() const { return count; }

template <class ItemType>
int DynamicQueue<ItemType>::Capacity() const { return capacity; }

template <class ItemType>
void DynamicQueue<ItemType>::Resize(int newCap) {
    ItemType* newItems = new ItemType[newCap];
    for (int i = 0; i < count; i++) {
        int idx = (front + i) % capacity;
        newItems[i] = items[idx];
    }
    delete[] items;
    items = newItems;
    capacity = newCap;
    front = 0;
    rear = count - 1;
}


template class DynamicQueue<int>;
// template class DynamicQueue<double>;
// template class DynamicQueue<char>;
template class DynamicQueue<std::string>;