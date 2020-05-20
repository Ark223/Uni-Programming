#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int l = p - start + 1;
    return (l == k) ? a[p] : (l > k) ?
        MedianOfMedians(a, k, start, p) :
        MedianOfMedians(a, k - l, p + 1, end);
}

int main() {
    int k, n = 10;
    vector<int> a = {5, 7, 1, 8, 6, 2, 0, 4, 9, 3};
    cout << "Ktory element znalezc? "; cin >> k;
    if (k > n || k < 1) { cout << "Zly element!"; return 0; }
    int res = n - MedianOfMedians(a, n - k + 1, 0, n) - 1;
    cout << "Wybrany element to: " << res << endl;
    return 0;
}
