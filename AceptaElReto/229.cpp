#include <iostream>

using namespace std;

int main() {
	long int i, num, suma, cont, sumaAux, v[100000];

	while (1) {
		cin >> num;
		if (!num) {
			break;
		}
		suma = 0, cont = 0, sumaAux = 0;
		for (i = 0; i < num; i++) {
			cin >> v[i];
			suma += v[i];
		}
		if (!suma) {
			cont += 1;
		}
		for (i = 0; i < num; i++) {
			sumaAux += v[i];
			suma -= v[i];
			if (sumaAux == suma) {
				cont++;
			}
		}
		cout << cont << endl;
	}
	return 0;
}

