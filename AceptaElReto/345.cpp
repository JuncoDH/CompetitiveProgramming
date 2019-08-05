#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 31543

int main() {
	int casos, z, i, j, k, l, flag;
	int v[9][9];
	int vaux[9][9] = { { 1, 1, 1, 2, 2, 2, 3, 3, 3 }, { 1, 1, 1, 2, 2, 2, 3, 3,
			3 }, { 1, 1, 1, 2, 2, 2, 3, 3, 3 }, { 4, 4, 4, 5, 5, 5, 6, 6, 6 }, {
			4, 4, 4, 5, 5, 5, 6, 6, 6 }, { 4, 4, 4, 5, 5, 5, 6, 6, 6 }, { 7, 7,
			7, 8, 8, 8, 9, 9, 9 }, { 7, 7, 7, 8, 8, 8, 9, 9, 9 }, { 7, 7, 7, 8,
			8, 8, 9, 9, 9 }

	};
	cin >> casos;
	for (z = 0; z < casos; z++) {
		flag = 0;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cin >> v[i][j];
			}
		}
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				for (k = 0; k < 9; k++) {
					if (v[i][k] == v[i][j] && k != j) {
						flag = 1;
						i = 9;
						j = 9;
						break;
					}
					if (v[k][j] == v[i][j] && k != i) {
						flag = 1;
						i = 9;
						j = 9;
						break;
					}
				}
				for (k = 0; k < 9; k++) {
					for (l = 0; l < 9; l++) {
						if (vaux[k][l] == vaux[i][j] && v[k][l] == v[i][j]
								&& (k != i || l != j)) {
							i = 9;
							j = 9;
							k = 9;
							l = 9;
							flag = 1;
							break;
						}
					}
				}
			}
		}
		if (flag) {
			cout << "NO\n";
		} else {
			cout << "SI\n";
		}
	}

	return 0;
}
