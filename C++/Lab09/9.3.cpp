#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

vector<int> Generate(int n) {
    vector<int> a;
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    return a;
}

void Reverse(vector<int> &a) {
    reverse(a.begin(), a.end());
}

void Shuffle(vector<int> &a) {
    random_shuffle(a.begin(), a.end());
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(vector<int> &a, int i, int j) {
    int c = a[i];
    while (i < j) {
        while (i < j && a[j] >= c) j--;
        while (i < j && a[i] < c) i++;
        if (i < j) Swap(&a[i], &a[j]);
    }
    return i;
}

int QuickSelect(vector<int> &a, int k, int n) {
    int i = 0, j = n - 1;
    while (i != j) {
        int p = Partition(a, i, j);
        p += 1 - i;
        if (p >= k) j = p + i - 1;
        else { k -= p; i += p; }
    }
    return a[i];
}

int Pivot(vector<int> &a, int start, int end, int mid) {
    int p = start, r = start, l = end - 1;
    while (r <= l) {
        if (a[r] == mid) r++;
        else if (a[r] < mid)
            Swap(&a[r++], &a[p++]);
        else
            Swap(&a[r], &a[l--]);
    }
    return p;
}

int MedianOfMedians(vector<int> &a, int k, int start, int end) {
    if (end - start <= 10) {
        sort(a.begin() + start, a.begin() + end);
        return a[start + k - 1];
    }
    vector<int> meds;
    for (int i = start; i < end; i += 5) {
        if (end - i <= 10) {
            sort(a.begin() + i, a.begin() + end);
            meds.push_back(a[(end + i) / 2]);
        } else {
            sort(a.begin() + i, a.begin() + i + 5);
            meds.push_back(a[i + 2]);
        }
    }
    int med = MedianOfMedians(meds,
        meds.size() / 2 + 1, 0, meds.size());
    int p = Pivot(a, start, end, med);
    int len = p - start + 1;
    return (k == len) ? a[p] : (k < len) ?
        MedianOfMedians(a, k, start, p) :
        MedianOfMedians(a, k - len, p + 1, end);
}

int main() {
    int n = 45000; //Rozmiar wektora
    for (int i = 0; i < 2; i++) {
        cout << (i == 0 ? "Test algorytmu Hoare'a" :
            "Test algorytmu magicznych piatek") << endl;
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k += 2647) {
                vector<int> a = Generate(n);
                if (j == 0) Reverse(a); else Shuffle(a);
                auto t1 = chrono::high_resolution_clock::now();
                int e = i == 0 ? QuickSelect(a, k, a.size()) :
                    n - MedianOfMedians(a, n - k + 1, 0, n) - 1;
                auto t2 = chrono::high_resolution_clock::now();
                auto dur = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
                cout << "Zbior: " << (j == 0 ? "odwrocony" : "losowy") <<
                    " - Element: " << k << " - Czas: " << dur << "ms" << endl;
            }
        }
    }
    return 0;
}
