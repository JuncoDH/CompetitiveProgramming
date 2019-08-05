#include <iostream>
#include <math.h>

using namespace std;

int reverse(int n) {
	int s = 0;
	while (n) {
		s *= 10;
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	int num, total, nuevo, viejo;
	while (1) {
		cin >> num;
		total = 0;
		if (num <= -1) {
			return 0;
		}
		viejo = num;
		while (1) {
			cin >> nuevo;
			if (nuevo == -1) {
				break;
			}
			total += abs(nuevo - viejo);
			viejo = nuevo;

		}
		cout << total << endl;

	}

	return 0;
}
