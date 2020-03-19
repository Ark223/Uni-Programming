#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const char alphabet[] = "0123456789ABCDEF";

int ValueToNumber(char c) {
    return (c >= '0' && c <= '9') ?
        ((int)c - '0') : ((int)c - 'A' + 10);
}

string ConvertToBase(int n, int base) {
    string a = "";
    do {
        a += alphabet[n % base];
        n /= base;
    }
    while (n > 0);
    reverse(a.begin(), a.end());
    return a;
}

int ConvertFromBase(string n, int base) {
    int len = n.length(), power = 1, a = 0;
    for (int i = len - 1; i >= 0; i--) {
        a += ValueToNumber(n[i]) * power;
        power *= base;
    }
    return a;
}

int main() {
    string a; int b1, b2;
    cout << "Wprowadz liczbe, jej baze oraz baze na jaka ma przejsc: " << endl;
    cin >> a >> b1 >> b2;
    int r1 = (b1 != 10) ? ConvertFromBase(a, b1) : atoi(a.c_str());
    string r2 = ConvertToBase(r1, b2);
    cout << "Wynik: " << r2 << endl;
    return 0;
}
