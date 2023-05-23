
#include <iostream>
#include <string>
using namespace std;
void sortowanie(string[], int);

void zadanie3(void) {
	const int n = 8;
	int m = n;
	string nazwaMiasta;
	string tablicaMiast[n];

	cout << "wczytaj nazwe 8 miast:" << endl;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, nazwaMiasta);
		if (nazwaMiasta[0] == '\0') { //pusty wiersz
			m = i;
			break;
		}
		tablicaMiast[i] = nazwaMiasta;
	}

	cout << "drukowanie zawartosci tablicy nieposortowanej" << endl;
	for (int i = 0; i < m; i++) {
		cout << tablicaMiast[i] << endl;
	}
	sortowanie(tablicaMiast, m);

};

void sortowanie(string t[], int k) { //sortowanie babelkowe
	cout << "drukowanie posortowanej tablicy" << endl;
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < k - i; j++) {
			if (t[j - 1] > t[j]) {
				t[j - 1].swap(t[j]);
			}
		}
	}

	for (int i = 0; i < k; i++) {
		cout << t[i] << endl;
	}

	system("Pause");
}





