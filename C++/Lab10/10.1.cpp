#include <iostream>
#include <string>
using namespace std;

class Queue {
    private:
        int size = 0; //aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        string* elements; // zbior elementow
    public:
        Queue(int capacity); // konstruktor
        ~Queue(); // destruktor
        // funkcje kolejki
        string Front();
        void Pop();
        void Push(string);
        int Size();
        bool IsEmpty();
        bool IsFull();
};

Queue::Queue(int cap) {
    capacity = cap;
    elements = new string[cap];
}

Queue::~Queue() {
    delete[] elements;
}

string Queue::Front() {
    return IsEmpty() ? "" : elements[0];
}

void Queue::Pop() {
    if (IsEmpty()) return;
    for (int i = 0; i < size; i++)
        elements[i] = elements[i + 1];
    size--;
}

void Queue::Push(string e) {
    if (IsFull()) return;
    elements[size++] = e;
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
    q.Push("3");
    q.Push("7");
    q.Push("15");
    cout << q.Front() << endl;
    q.Pop();
    cout << q.Front() << endl;
    return 0;
}
