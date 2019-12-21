#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;

#define show(x) cout<<":"<<x<<endl

int values[1000000];
string s;

void subir(string cad) {
	int i = 0;
	for (i = 0; i < cad.length(); i++) {
		if (cad[i] >= 'A' && cad[i] <= 'Z') {
			values[i] = cad[i] - 'A' + 10;
		} else if (cad[i] >= 'a' && cad[i] <= 'z') {
			values[i] = cad[i] - 'a' + 10;
		} else {
			values[i] = cad[i] - '0';
		}
	}
}

void reducir(int base, int n) {
	int i;
	for (i = n - 1; i > 0; i--) {
		values[i - 1] += values[i];
		values[i - 1] %= (base - 1);
	}
}

int main() {
	int B, casos, z;
	string D, d, c, r;
	int DD, dd, cc, rr;

	cin >> casos;
	for (z = 0; z < casos; z++) {
		cin >> B >> D >> d >> c >> r;
		subir(D);
		reducir(B, D.length());
		DD = values[0];

		subir(d);
		reducir(B, d.length());
		dd = values[0];

		subir(c);
		reducir(B, c.length());
		cc = values[0];

		subir(r);
		reducir(B, r.length());
		rr = values[0];

		if (((DD - dd * cc) % (B - 1) + B - 1) % (B - 1)
				== (rr % (B - 1) + B - 1) % (B - 1)) {
			cout << "POSIBLEMENTE CORRECTO\n";
		} else {
			cout << "INCORRECTO\n";
		}
	}
	return 0;
}
