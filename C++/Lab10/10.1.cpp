#include <iostream>
using namespace std;

class Queue {
    private:
        int size = 0; //aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        int* elements; // zbior elementow
    public:
        Queue(int size); // konstruktor
        ~Queue(); // destruktor
        // funkcje kolejki
        void Pop();
        void Push(int);
        int Top();
        int Size();
        bool IsEmpty();
        bool IsFull();
};

Queue::Queue(int cap) {
    capacity = cap;
    elements = new int[cap];
}

Queue::~Queue() {
    delete[] elements;
}

void Queue::Pop() {
    if (IsEmpty()) return;
    for (int i = 0; i < size; i++)
        elements[i] = elements[i + 1];
    size--;
}

void Queue::Push(int e) {
    if (IsFull()) return;
    elements[size++] = e;
}

int Queue::Top() {
    return IsEmpty() ? 0 : elements[0];
}

int Queue::Size() {
    return size;
}

bool Queue::IsEmpty() {
    return size == 0;
}

bool Queue::IsFull() {
    return size == capacity;
}

int main() {
    Queue q(10);
    q.Push(3);
    q.Push(7);
    q.Push(15);
    cout << q.Top() << endl;
    q.Pop();
    cout << q.Top() << endl;
    return 0;
}
