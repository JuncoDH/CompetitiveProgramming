#include <iostream>
#include <math.h>

using namespace std;

int sum(int num) {
	int n = log10(num) + 1, suma = 0;
	switch (n) {
	case 7:
		suma = 5888896;
		break;
	case 6:
		suma = 6 * (num - 99999) + 488889;
		break;
	case 5:
		suma = 5 * (num - 9999) + 38889;
		break;
	case 4:
		suma = 4 * (num - 999) + 2889;
		break;
	case 3:
		suma = 3 * (num - 99) + 189;
		break;
	case 2:
		suma = 2 * (num - 9) + 9;
		break;
	case 1:
		suma = num;
		break;

	}
	return suma;
}

int calc(int suma) {
	if (suma < 10) {
		return suma;
	}
	if (suma < 190) {
		return ((suma - 9) / 2) + 9;
	}
	if (suma < 2890) {
		return ((suma - 189) / 3) + 99;
	}
	if (suma < 38890) {
		return ((suma - 2889) / 4) + 999;
	}

	if (suma < 488890) {
		return ((suma - 38889) / 5) + 9999;
	}
	if (suma < 5888897) {
		return ((suma - 488889) / 6) + 99999;
	}
	return 1000000;

	return 0;
}

int main() {
	int n, m, distancia, vn, vm;
	n = 99;
	m = 101;
	while (1) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}
		vn = sum(n);
		vm = sum(m);
		distancia = vm - vn + int(log10(n) + 1);
		cout << calc(vn + int(distancia / 2) - int(log10(n) + 1)) << endl;

	}

	return 0;
}
