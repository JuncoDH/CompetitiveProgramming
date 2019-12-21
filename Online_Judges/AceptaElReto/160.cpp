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
	int i, j, n, v[50][50], t1, t2;

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
		t1 = 0;
		t2 = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (v[i][j] && i != j) {
					if (i < j) {
						t1 = 1;
					} else {
						t2 = 1;
					}
				}
			}
		}
		if (t1 && t2) {
			cout << "NO\n";
		} else {
			cout << "SI\n";
		}

	}

	return 0;
}
