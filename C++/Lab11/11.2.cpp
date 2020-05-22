#include <iostream>
#include <string>
using namespace std;

// Stos

class Stack {
    private:
        int size = 0;
        int capacity;
        int* elements;
    public:
        Stack(int capacity);
        ~Stack();
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
        if (str[0] == '=') { // ostatni znak to =, a zatem mamy wynik..
            cout << "Wynik: " << s.Top() // zwroc wartosc ostatniego elementu stosu
                << endl; return 0;
        }
        else if (IsDigit(str[0])) { // czy znak jest cyfra
            a = 0; b = 0;
            while (str[b]) // zamien znaki na liczbe (koncz przy spacji)
                a = a * 10 + str[b++] - 48;
            s.Push(a); continue; // dodaj otrzymana liczbe do stosu
        }
        b = s.Top(); s.Pop(); // zdejmij ze stosu jedna i druga liczbe
        a = s.Top(); s.Pop();
        switch (str[0]) { // dokonaj dzialania
            case '+': c = a + b; break;
            case '-': c = a - b; break;
            case '*': c = a * b; break;
            case '/': c = a / b; break;
        } s.Push(c); // wloz wynik dzialania do stosu
    }
    return 0;
}
