#include <iostream>
using namespace std;

class Stack {
    private:
        int size = 0; //aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        int* elements; // zbior elementow
    public:
        Stack(int capacity); // konstruktor
        ~Stack(); // destruktor
        // funkcje kolejki
        void Pop();
        void Push(int);
        int Top();
        int Size();
        bool IsEmpty();
        bool IsFull();
};

Stack::Stack(int cap) {
    capacity = cap;
    elements = new int[cap];
}

Stack::~Stack() {
    delete[] elements;
}

void Stack::Pop() {
    if (IsEmpty()) return;
    elements[--size] = 0;
}

void Stack::Push(int e) {
    if (IsFull()) return;
    elements[size++] = e;
}

int Stack::Top() {
    return IsEmpty() ? 0 : elements[size - 1];
}

int Stack::Size() {
    return size;
}

bool Stack::IsEmpty() {
    return size == 0;
}

bool Stack::IsFull() {
    return size == capacity;
}

int main() {
    Stack s(10);
    s.Push(3);
    s.Push(7);
    s.Push(15);
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    return 0;
}
