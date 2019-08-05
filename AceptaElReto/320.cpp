#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int v[100000];

int main() {
	int i, peso, final, cont, palmeras, maxcadlong, z, casos;
	cin >> casos;
	for (z = 0; z < casos; z++) {
		cin >> peso >> final;
		for (i = 0; i < final; i++) {
			cin >> v[i];
		}

		cont = 0;
		palmeras = 0;
		maxcadlong = 0;

		for (i = 0; i < final; i++) {
			if (v[i] - peso >= 0) {
				palmeras++;

				while (palmeras > 5 && cont < i) {
					if (v[cont] - peso >= 0) {
						palmeras--;
					}
					cont++;
				}

			}
			maxcadlong = max(maxcadlong, abs(i - cont) + 1);

		}
		cout << maxcadlong << endl;
	}
	return 0;
}
