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

#define MAX 1005

char arr[1001][1001];

int puedo(int x, int y, int limx, int limy) {
	if (x < 0 || y < 0 || x >= limx || y >= limy || arr[x][y] == '-') {
		return 0;
	}
	return 1;
}

int main() {
	int i, j, x, y, cont, total;
	string s1, s2;
	while (1) {
		cin >> x >> y;
		if (!x || !y) {
			return 0;
		}
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				cin >> arr[i][j];
			}
		}

		total = 0;
		for (i = 0; i < y; i++) {
			for (j = 0; j < x; j++) {
				cont = 0;
				if (arr[i][j] == '*') {
					continue;
				}
				if (puedo(i - 1, j - 1, y, x)) {
					cont++;
				}
				if (puedo(i - 1, j, y, x)) {
					cont++;
				}
				if (puedo(i - 1, j + 1, y, x)) {
					cont++;
				}
				if (puedo(i, j - 1, y, x)) {
					cont++;
				}
				if (puedo(i, j + 1, y, x)) {
					cont++;
				}
				if (puedo(i + 1, j - 1, y, x)) {
					cont++;
				}
				if (puedo(i + 1, j, y, x)) {
					cont++;
				}
				if (puedo(i + 1, j + 1, y, x)) {
					cont++;
				}
				if (cont >= 6) {
					total++;
				}
			}
		}
		cout << total << endl;

	}
	return 0;
}
