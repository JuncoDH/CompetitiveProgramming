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

int main() {
	int i, j, n, v[50][50], t;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		t = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (v[i][j]) {
					if (i != j || v[i][j] != 1) {
						t = 1;
						i = n;
						break;
					}
				} else {
					if (i == j) {
						t = 1;
						i = n;
						break;
					}
				}
			}
		}

		if (t) {
			cout << "NO\n";
		} else {
			cout << "SI\n";
		}

	}

	return 0;
}
