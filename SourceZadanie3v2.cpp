
#include <iostream>
using namespace std;
void sortowanie(char**, int);

void zadanie5(void) {

	const int n = 8;
	int m = n;
	char* ptab[n];
	const int maxDlugosc = 80;
	char tabTemp[maxDlugosc];

	cout << "wczytaj nazwe 8 miast:" << endl;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cin.getline(tabTemp, maxDlugosc);
		if (tabTemp[0] == '\0') { //pusty wiersz
			m = i;
			break;
		}
		ptab[i] = new char[strlen(tabTemp) + 1];
		strcpy_s(ptab[i], strlen(tabTemp) + 1, tabTemp);
	}

	cout << "drukowanie zawartoœci tablicy nieposortowanej" << endl;
	for (int i = 0; i < m; i++) {
		cout << ptab[i] << endl;
	}

	sortowanie(ptab, m);

	for (int i = 0; i < m; i++) {
		delete[] ptab[i];
	}

}

void sortowanie(char** pt, int k) {
	cout << "drukowanie posortowanej tablicy" << endl;
	char* s;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (_stricmp((pt[i]), (pt[j])) > 0) {
				s = new char[strlen(pt[i]) + 1];
				strcpy_s(s, strlen(pt[i]) + 1, pt[i]);
				strcpy_s(pt[i], strlen(pt[j]) + 1, pt[j]);
				strcpy_s(pt[j], strlen(s) + 1, s);
				delete[] s;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cout << pt[i] << endl;
		//delete pt[i]; //wyrzuca bl¹d, chyba ¿e nazwy s¹ tej samej dlugosci - problem ze zwalnieniem blokow pamiêci po wymieszaniu ?
	}
}


