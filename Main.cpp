#include "Header.h"
#include <iostream>
using namespace std;

void main (void) {
	int ktore;
	cout << "Ktore zadanie uruchomic: ";
	cin >> ktore;
	switch (ktore) {
	case 1: zadanie1();
		break;
	case 2: zadanie2();
		break;
	case 3: zadanie3();
		break;
	case 4: zadanie4();
		break;
	case 5: zadanie5();
	};
	
}