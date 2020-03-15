#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int a = 1, b, r = rand() % 15 + 1;
	while (true) {
		cout << "Zgadnij liczbe od 1 do 15: " << endl;
		cin >> b;
		if (b > r) (cout << "Podana liczba jest wieksza od wylosowanej" << endl);
		else if (b < r) (cout << "Podana liczba jest mniejsza od wylosowanej" << endl);
		else (cout << "Trafiles po " << a << " probach!" << endl);
		if (r == b) break; a++;
	}
	return 0;
}

