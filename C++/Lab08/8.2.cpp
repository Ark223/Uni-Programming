#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(vector<int> &a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                Swap(&a[j], &a[j + 1]);
}

void InsertionSort(vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j]; j -= 1;
        } a[j + 1] = k;
    }
}

void SelectionSort(vector<int> &a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[k]) k = j;
        Swap(&a[k], &a[i]);
    }
}

int Divide(vector<int> &a, int start, int end) {
    int pivot = a[end], i = start - 1;
    for (int j = start; j <= end - 1; j++)
        if (a[j] < pivot) { i++; Swap(&a[i], &a[j]); }
    Swap(&a[i + 1], &a[end]);
    return i + 1;
}

void QuickSort(vector<int> &a, int start, int end) {
    if (start >= end) return;
    int p = Divide(a, start, end);
    QuickSort(a, start, p - 1);
    QuickSort(a, p + 1, end);
}

void Merge(vector<int> &a, int start, int mid, int end) {
    int i, j, k, t[(end - start)];
    for (i = start; i <= end; i++) t[i] = a[i];
    i = start; j = mid + 1; k = start;
    while (i <= mid && j <= end) {
        if (t[i] < t[j]) a[k++] = t[i++];
        else a[k++] = t[j++];
    }
    while (i <= mid) a[k++] = t[i++];
}

void MergeSort(vector<int> &a, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    MergeSort(a, start, mid);
    MergeSort(a, mid + 1, end);
    Merge(a, start, mid, end);
}

int main() {
    string line;
    ifstream file("10.txt");
    while (getline(file, line)) {
        stringstream is(line);
        vector<int> a((istream_iterator<int>(is)),
            istream_iterator<int>());
        QuickSort(a, 0, a.size() - 1);
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " " << endl;
        return 0;
    }
    return 0;
    //clock_t start = clock();
}
