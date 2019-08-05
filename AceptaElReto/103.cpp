#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

int arr[21], gr;

double f(double num) {
	int i;
	double suma = 0, coef;
	suma = arr[0];
	coef = 1;
	for (i = 1; i <= gr; i++) {
		coef *= num;
		suma += (coef * arr[i]);
	}

	return suma;
}

int main() {
	int i;
	double suma, n, temp;
	while (1) {
		cin >> gr;
		if (gr == 20) {
			return 0;
		}
		for (i = gr; i >= 0; i--) {
			cin >> arr[i];
		}
		suma = 0;
		cin >> n;
		for (i = 0; i < n; i++) {
			temp = f(i * (1.0 / n));
			if (temp < 0) {
				continue;
			}
			if (temp > 1) {
				temp = 1;
			}
			suma += (1.0 / n) * temp;
		}
		//show(suma);
		if (suma < 0.499) {
			cout << "ABEL\n";
		} else if (suma > 0.501) {
			cout << "CAIN\n";
		} else {
			cout << "JUSTO\n";
		}
	}
	return 0;
}
