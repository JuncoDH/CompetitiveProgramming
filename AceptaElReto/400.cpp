#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string cad;
	int r1 = 0, r2 = 0, r3 = 0, temp = 0;
	unsigned i;

	while (cin >> cad) {
		r1 = 0;
		r2 = 0;
		r3 = 0;
		for (i = 0; i < cad.length(); i++) {
			if (cad[i] == 'X') {
				break;
			}
		}
		r1 = i;
		for (temp = 0; i < cad.length(); i++) {
			if (cad[i] == 'X') {
				r2 = max(r2, temp);
				temp = 0;
				continue;
			}
			temp++;
			if (i == cad.length() - 1) {
				r3 = temp;
			}

		}
		cout << max(r1 - 1, max(r3 - 1, (r2 - 1) / 2)) << endl;

	}
	return 0;
}

