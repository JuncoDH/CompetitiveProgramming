#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int pol(long long n) {
	int cont = int(log10(n)) + 1;

	for (; cont > 0; cont--) {
		if (n % cont) {
			return 0;
		}
		n /= 10;
	}

	return 1;
}

void divi(long long int n, long long int d) {
	if (n <= 0) {
		return;
	}
	int i;
	long long int suma;
	if (!pol(n)) {
		return;

	}
	cout << n << endl;
	if (int(log10(n) + 1) == d) {
		return;
	}
	for (i = 0; i < 10; i++) {
		suma = n * 10 + i;
		divi(suma, d);
	}

}

int main() {
	long long int n, d;

	while (cin >> n) {
		cin >> d;
		divi(n, d);
		cout << "---\n";

	}

	return 0;
}

