#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int i, j, n, d, casos, z, flag;
	int v[1007][7] = { 0 };
	for (i = 1000; i < 1007; i++) {
		for (j = 1; j < 7; j++) {
			v[i][j]++;
		}
	}
	for (i = 998; i >= 0; i--) {
		if (!v[i + 1][2] && !v[i + 1][3] && !v[i + 1][4] && !v[i + 1][5]) {
			v[i][1]++;
		}
		if (!v[i + 2][1] && !v[i + 2][4] && !v[i + 2][3] && !v[i + 2][6]) {
			v[i][2]++;
		}
		if (!v[i + 3][1] && !v[i + 3][2] && !v[i + 3][5] && !v[i + 3][6]) {
			v[i][3]++;
		}
		if (!v[i + 4][1] && !v[i + 4][2] && !v[i + 4][5] && !v[i + 4][6]) {
			v[i][4]++;
		}
		if (!v[i + 5][1] && !v[i + 5][4] && !v[i + 5][3] && !v[i + 5][6]) {
			v[i][5]++;
		}
		if (!v[i + 6][2] && !v[i + 6][3] && !v[i + 6][4] && !v[i + 6][5]) {
			v[i][6]++;
		}

	}
	cin >> casos;
	for (z = 0; z < casos; z++) {
		cin >> n >> d;
		flag = 0;
		switch (d) {
		case 1:
			if (v[n][2] || v[n][3] || v[n][4] || v[n][5]) {
				flag = 1;
			}
			break;
		case 2:
			if (v[n][1] || v[n][3] || v[n][4] || v[n][6]) {
				flag = 1;
			}
			break;
		case 3:
			if (v[n][1] || v[n][2] || v[n][5] || v[n][6]) {
				flag = 1;
			}
			break;
		case 4:
			if (v[n][1] || v[n][2] || v[n][5] || v[n][6]) {
				flag = 1;
			}
			break;
		case 5:
			if (v[n][1] || v[n][3] || v[n][4] || v[n][6]) {
				flag = 1;
			}
			break;
		case 6:
			if (v[n][2] || v[n][3] || v[n][4] || v[n][5]) {
				flag = 1;
			}
			break;
		}
		cout << (flag ? "GANA\n" : "PIERDE\n");
	}
	return 0;
}

