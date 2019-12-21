#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main() {
	int n, k, i, medida, cont, maxcont, contCeros;

	while (1) {
		cin >> n >> k;
		if (!n && !k) {
			return 0;
		}
		maxcont = 0;
		cont = 0;
		contCeros = 0;
		for (i = 0; i < n; i++) {
			cin >> medida;
			if (medida) {
				cont++;
				maxcont = max(1, maxcont);
				for (i++; i < n; i++) {
					cont++;
					cin >> medida;
					if (!medida) {
						contCeros++;
					}
					if (contCeros > k) {
						cont = 0;
						contCeros = 0;
						break;
					}
					if (medida) {
						contCeros = 0;
						maxcont = max(cont, maxcont);
					}

				}
			}
		}
		cout << maxcont << endl;
	}

	return 0;
}
