#include <iostream>
#include <string>
using namespace std;

class Stack {
    private:
        int size = 0; //aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        string* elements; // zbior elementow
    public:
        Stack(int capacity); // konstruktor
        ~Stack(); // destruktor
        // funkcje kolejki
        void Pop();
        void Push(string);
        string Top();
        int Size();
        bool IsEmpty();
        bool IsFull();
};

Stack::Stack(int cap) {
    capacity = cap;
    elements = new string[cap];
}

Stack::~Stack() {
    delete[] elements;
}

void Stack::Pop() {
    if (IsEmpty()) return;
    elements[--size] = "";
}

void Stack::Push(string e) {
    if (IsFull()) return;
    elements[size++] = e;
}

string Stack::Top() {
    return IsEmpty() ? "" : elements[size - 1];
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
    s.Push("3");
    s.Push("7");
    s.Push("15");
    cout << s.Top() << endl;
    s.Pop();
    cout << s.Top() << endl;
    return 0;
}
