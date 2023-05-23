
#include <iostream>
#include <conio.h>
using namespace std;

void zadanie1(void) {
	bool daneDobre = false;
	static int n, k, j, counter;
	const int arraySize = 200;
	const int limit = 99;
	char ch;
	char tab[arraySize];

	do {
		cout << "liczba wszystkich dzieci (99 max): ";
		cin >> n;
		cout << "liczba dziewczynek jakie maja stac obok siebie: ";
		cin >> k;
		if (0 < k && k < n && n <= limit) {
			daneDobre = true;
			cout << "wprowadziles prawidlowe liczby: " << n << " i " << k << endl;
		}
		else {
			cout << "wprowadziles bledne dane" << endl;
		}
	} while (!daneDobre);

	cout << "Wprowadzaj ciag 0 i 1" << endl;
	cout << "0 oznacza dziewczynke, 1 chlopca" << endl;
	cin.ignore();
	int i = 0;
	do {
		ch = _getch();
		cout << ch;
		if (ch == '0' || ch == '1') {
			tab[i] = ch;
			i++;
		}
	} while (i <= n);

	cout << endl << "wprowadziles dane: ";
		for (int i = 0; i < n; i ++ ) {
			cout << tab[i];
		}
	cout << endl;

	bool LED = false;
	int minLicznikPetli = n;
	for (int i = 0; i<n; i++) { //punkt startowy
		int licznikPetli = 0;
		int licznikDziewczynek = 0;
		for (int j = i; j<n; j ++) { //przeszukiwanie do koñca tablicy od punktu startowego
			if (tab[j] == '0') licznikDziewczynek ++;
			licznikPetli++; //ile potrzbujê iteracji w petli wewnetrznej by "uzbieraæ" k dziewczynek
			if (licznikDziewczynek >= k) {
				if (licznikPetli < minLicznikPetli) { minLicznikPetli = licznikPetli; } //zapamiêtujê petle z najmniejsza liczba iteracji
				LED = true; 
				break;
			}
		}
	}

	if (LED) {
	cout << (minLicznikPetli - k) << endl;
	}
	else cout << "NIE" << endl;

	system("Pause");

}

