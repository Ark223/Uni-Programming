#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool IsPerfect(int n) {
    int a = 1, b = sqrt(n);
    for (int i = 2; i <= b; i++)
        if (n % i == 0) a += i + n / i;
    if (n == pow(b, 2)) a -= b;
    return (a == n) ? true : false;
}

int main() {
    vector<int> a, b;
    for (int i = 2; i <= 30; i++) {
        if (IsPerfect(i)) a.push_back(i);
        else b.push_back(i);
    }
    cout << "Liczby doskonale z przedzialu <2; 30>: " << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " "; cout << endl;
    cout << "Liczby niedoskonale z przedzialu <2; 30>: " << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " "; cout << endl;
    return 0;
}
