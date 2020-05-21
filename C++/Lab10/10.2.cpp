#include <iostream>
using namespace std;

struct Node {
    int value, priority;
};

class PriorityQueue {
    private:
        int size = 0; //aktualna ilosc elementow
        int capacity; // pojemnosc kolejki
        Node* elements; // zbior elementow
    public:
        PriorityQueue(int capacity); // konstruktor
        ~PriorityQueue(); // destruktor
        // funkcje kolejki
        void Pop();
        void Push(int, int);
        Node Top();
        int Size();
        bool IsEmpty();
        bool IsFull();
};

PriorityQueue::PriorityQueue(int cap) {
    capacity = cap;
    elements = new Node[cap];
}

PriorityQueue::~PriorityQueue() {
    delete[] elements;
}

void PriorityQueue::Pop() {
    if (IsEmpty()) return;
    for (int i = 0; i < size; i++)
        elements[i] = elements[i + 1];
    size--;
}

void PriorityQueue::Push(int v, int p) {
    if (IsFull()) return;
    Node n = {v, p};
    int i = size;
    while (i > 0 && n.priority >=
        elements[i - 1].priority) i--;
    for (int j = i; j < size; j++)
        elements[j + 1] = elements[j];
    elements[i] = n; size++;
}

Node PriorityQueue::Top() {
    return IsEmpty() ? Node{0, 0} : elements[0];
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
    pq.Push(3, 2);
    pq.Push(2, 3);
    pq.Push(7, 1);
    pq.Push(15, 2);
    cout << pq.Top().value << endl;
    pq.Pop();
    cout << pq.Top().value << endl;
    return 0;
}
