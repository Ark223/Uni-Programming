#include <iostream>
#include <string>
using namespace std;

// Stos

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

// ONP

bool IsDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    Stack s(20); int a, b, c; string str;
    cout << "Podaj wyrazenie w notacji ONP: " << endl;
    while (1) {
        cin >> str;
        if (str[0] == '=') {
            cout << "Wynik: " << s.Top()
                << endl; return 0;
        }
        else if (IsDigit(str[0])) {
            a = 0; b = 0;
            while (str[b])
                a = a * 10 + str[b++] - 48;
            s.Push(a); continue;
        }
        b = s.Top(); s.Pop();
        a = s.Top(); s.Pop();
        switch (str[0]) {
            case '+': c = a + b; break;
            case '-': c = a - b; break;
            case '*': c = a * b; break;
            case '/': c = a / b; break;
        } s.Push(c);
    }
    return 0;
}
