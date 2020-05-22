#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    int priority;
};

class PriorityQueue {
    private:
        int size = 0; // aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        Node* elements; // zbior elementow
    public:
        PriorityQueue(int capacity); // konstruktor
        ~PriorityQueue(); // destruktor
        // funkcje kolejki
        Node Front(); // zwroc pierwszy element
        void Pop(); // usun pierwszy element
        void Push(string, int); // wloz element w odpowiednie miejsce
        int Size(); // zwroc ilosc elementow w kolejce
        bool IsEmpty(); // sprawdz czy kolejka jest pusta
        bool IsFull(); // sprawdz czy kolejka jest pelna
};

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    elements = new Node[cap];
}

PriorityQueue::~PriorityQueue() {
    delete[] elements;
}

Node PriorityQueue::Front() {
    return IsEmpty() ? Node{"", 0} : elements[0];
}

void PriorityQueue::Pop() {
    if (IsEmpty()) return;
    for (int i = 0; i < size; i++)
        elements[i] = elements[i + 1]; // przesun elementy do poczatku
    elements[--size] = Node{"", 0}; // okresl ostatni byly element jako pusty
}

void PriorityQueue::Push(string v, int p = 0) {
    if (IsFull()) return;
    Node n = {v, p};
    int i = size; // sugerowane miejsce dla nowego elementu
    while (i > 0 && n.priority >= // w przypadku gdy element posiada wiekszy priorytet..
        elements[i - 1].priority) i--; // znajdz odpowiednie miejsce dla elementu
    for (int j = i; j < size; j++) // przesun sprawdzane elementy o 1 miejsce w prawo..
        elements[j + 1] = elements[j]; // aby zarezerwowac miejsce dla nowego elementu
    elements[i] = n; size++;
}

int PriorityQueue::Size() {
    return size;
}

bool PriorityQueue::IsEmpty() {
    return size == 0;
}

bool PriorityQueue::IsFull() {
    return size == capacity;
}

int main() {
    PriorityQueue pq(10);
    pq.Push("3", 2);
    pq.Push("2", 3);
    pq.Push("7", 1);
    pq.Push("15", 2);
    cout << pq.Front().value << endl;
    pq.Pop();
    cout << pq.Front().value << endl;
    return 0;
}
