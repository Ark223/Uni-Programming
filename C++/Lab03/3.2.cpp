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
	int a, b;
	cout << "Wpisz pierwsza liczbe: " << endl;
	cin >> a;
	cout << "Wpisz druga liczbe: " << endl;
	cin >> b;
	cout << "Najwiekszy wspolny dzielnik: " << NWD(a, b) << endl;
	cout << "Najmniejsza wspolna wielokrotnosc: " << (a * b / NWD(a, b)) << endl;
	return 0;
}

