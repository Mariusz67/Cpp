#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Car {
private:
	string marka;
	int przebieg;
	int wartosc;

public:

	Car() {
		marka = "fiat";
		przebieg = 100000;
		wartosc = 20000;
	};

	Car(string s, int p, int w) {
		marka = s;
		przebieg = p;
		wartosc = w;
	};


	Car(const Car& samochod) {  // gdyby zamiast String marka by³o char* marka, wówczas potrzebna jest g³êboka kopia
		// Car(const Car & samochod) { this->marka = (strcpy(new char[strlen(samochod.marka)+1],samochod.marka)) };
		marka = samochod.marka;
		przebieg = samochod.przebieg;
		wartosc = samochod.wartosc;
	};


	void wypiszDane() {
		cout << "dane samochodu:" << endl;
		cout << "marka: " << marka << endl;
		cout << "przebieg: " << przebieg << endl;
		cout << "wartosc: " << wartosc << endl;
	};

	//~Car() {
	//	delete[] marka;
	//}

	Car& operator=(Car&);
	friend ostream& operator<<(ostream&, const Car&);
	friend bool operator==(const Car&, const Car&);
	Car& operator-(int n);
	friend Car& operator+(const Car&, const Car&);
	Car& operator+=(const Car&);
};


Car& Car::operator=(Car& c) {
	// gdyby zamiast String marka by³o char* marka, wówczas potrzebna jest g³êboka kopia
	// https://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node123.html
	if (this != &c) {
		// delete [] marka 
		//marka (strcpy(new char[strlen(c.marka)+1],c.marka))
		this->marka = c.marka;
		this->przebieg = c.przebieg;
		this->wartosc = c.wartosc;
	}
	return *this;
}



ostream& operator<<(ostream& os, const Car& c) {
	os << "marka: " << c.marka << " * przebieg: " << c.przebieg << " * wartosc: " << c.wartosc << endl;
	return os;
}

bool operator==(const Car& c1, const Car& c2) {
	if ((c1.marka == c2.marka) && (c1.przebieg == c2.przebieg)) return true;
	else return false;
};

Car& Car::operator-(int n) {
	this->przebieg = this->przebieg - n;
	return *this;
};

Car& operator+(const Car& c1, const Car& c2) {
	Car tempCar;
	if (c1.wartosc >= c2.wartosc) tempCar.marka = c1.marka;
	else tempCar.marka = c2.marka;
	double wsp1 = 1.2;
	tempCar.wartosc = wsp1 * 0.5 * (c1.wartosc + c2.wartosc);
	double wsp2 = 0.7;
	if (c1.przebieg < c2.przebieg) tempCar.przebieg = c1.przebieg * wsp2;
	else tempCar.przebieg = c2.przebieg * wsp2;
	//cout << "tempCar marka: " << tempCar.marka;
	return tempCar; //nie jest przekazywana ca³a kopia obiektu?
};

Car& Car::operator+=(const Car& c) {
	int k = 10000;
	if (this->wartosc < c.wartosc) this->wartosc = this->wartosc + k;
	return *this;
};

int zadanie2() {
	Car mojeAuto;
	mojeAuto.wypiszDane();
	cout << endl << "moje auto: " << mojeAuto << endl;
	Car autoZony("fiat", 50000, 25000);
	cout << "auto zony: " << autoZony;
	if (!(mojeAuto == autoZony)) cout << "moje auto ma inny przebieg" << endl;
	Car autoKtoreSprzedalem;
	autoKtoreSprzedalem = mojeAuto;
	cout << endl << "dane samochodu jaki sprzedalem: " << endl;
	autoKtoreSprzedalem.wypiszDane();
	Car mojeNoweAuto(autoZony);
	cout << endl << "dane mojego nowego samochodu: " << endl;
	mojeNoweAuto.wypiszDane();
	int cofnijLicznik = 20000;
	mojeNoweAuto - cofnijLicznik;
	cout << endl << "dane samochodu po cofnieciu licznika: " << endl;
	mojeNoweAuto.wypiszDane();
	Car autoZeSzrotu("polonez", 300000, 5000);
	Car autoOdHandlarza("fiat", 200000, 10000);
	Car skladak;
	skladak = autoZeSzrotu + autoOdHandlarza;
	cout << endl << "dane skladaka: " << endl;
	skladak.wypiszDane(); //nie drukuje marki nie wiem dlaczego
	//cout << "test "<<skladak<<endl;
	autoZeSzrotu += autoOdHandlarza;
	cout << endl << "auto po wzbogaceniu: " << endl;
	autoZeSzrotu.wypiszDane();

	return 0;
}