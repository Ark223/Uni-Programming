#include <iostream>
using namespace std;

int NWD(int a, int b) {
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b, c, d;
    cout << "Wpisz pierwsza liczbe: " << endl;
    cin >> a;
    cout << "Wpisz druga liczbe: " << endl;
    cin >> b;
	int c = NWD(a, b);
	int d = a * b / c;
    cout << "Najwiekszy wspolny dzielnik: " << c << endl;
    cout << "Najmniejsza wspolna wielokrotnosc: " << d << endl;
    return 0;
}
