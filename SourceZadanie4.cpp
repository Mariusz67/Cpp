#include <iostream>
using namespace std;
struct pracownik {
	string imie;
	string nazwisko;
	char* stanowisko;
	double pensja;
	char plec;
};
void wypelnij(pracownik*, int);
void wydrukuj(pracownik*,int);

void zadanie4(void) {
	int n;
	cout << "podaj liczbe pracownikow" << endl;
	cin >> n;
	pracownik* ptab = new pracownik[n];
	wypelnij(ptab, n);
	wydrukuj(ptab,n);
}

void wypelnij(pracownik* tablica, int liczba) {

	char ch;
	string temp;
	bool good = true;
	cout << "wypelniam tablice danymi" << endl;
	for (int i = 0; i < liczba; i++) {
		cout << "pracownik nr: " << i+1 << endl;
		temp = "";
		cout << "podaj imie i nazwisko" << endl; //tutaj znaki nie bedace literami lub spacja sa ignorowane
		cin.ignore();
		do {
			ch = getchar();
			if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch==' ')
				temp.push_back(ch);
		} while (ch != '\n' || temp.size() == 0); //¿eby nie wprowadziæ pustego wiersza
		tablica[i].imie = temp;

		cout << "podaj stanowisko" << endl; //inny sposob walidacji - po wprowadzeniu calego wiersza
		do { 
			good = true;
			tablica[i].stanowisko = new char[50];
			do {
				cin.getline(tablica[i].stanowisko, 49);
			} while (strlen(tablica[i].stanowisko) < 1); //pusty wiersz
			for (int j = 0; j < strlen(tablica[i].stanowisko) / sizeof'a'; j++) {
				ch = tablica[i].stanowisko[j];
				if (!('a' <= ch && ch <= 'z') && !('A' <= ch && ch <= 'Z') && ch != ' ') {
					cout << "wprowadziles zle dane, sprobuj jeszcze raz" << endl;
					good = false;
					break;
				}
			}
			if (!good) {
				delete tablica[i].stanowisko;
			}
		} while (!good);

		cout << "podaj pensje" << endl; //walidacja cin.fail() - nie jest idealna ale dzia³a 
		bool error = false;
		double liczbaDouble = 0;
		do {
			cin >> tablica[i].pensja;
			error = cin.fail();
			if (!error) continue;
			cout << "podaj pensje jako liczbe" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		} while (error);
			

		cout << "podaj plec K lub M" << endl; //dziala bardzo dobrze
		error = true;
		do {
			cin.ignore(100,'\n');
			do {
				ch = getchar();
			} while (ch == '\n'); //odporne na pusty wiersz
			if (ch == 'k' || ch == 'K' || ch == 'm' || ch == 'M') {
				error = false;
				break;
			}
			else {
				cout << "podaj K lub M" << endl;
			}
		} while (error);
		tablica[i].plec = ch;
	}

}

void wydrukuj(pracownik* tablica, int liczba) {
	cout << "drukuje zawartosc tablicy" << endl;
	for (int i = 0; i < liczba; i++) {
		cout << "imie i nazwisko: " << tablica[i].imie << " " << endl;
		cout << "stanowisko: " << tablica[i].stanowisko << endl;
		cout << "pensja: " << tablica[i].pensja<< endl;
		cout << "plec: " << tablica[i].plec<<endl;
		delete tablica[i].stanowisko;
	}
	delete[] tablica;
}