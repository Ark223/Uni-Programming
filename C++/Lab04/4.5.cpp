#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cout << "Podaj wyraz: " << endl;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    cout << "Podany wyraz" << ((a != b) ? " nie" : "")
        << " jest palindromem" << endl;
    return 0;
}
