#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 31543

int main() {

	int n, c, i, j, minimo, imin, temp;
	while (cin >> n) {
		vector<int> v(n);
		cin >> c;
		for (i = 0; i < c; i++) {
			minimo = v[0];
			imin = 0;
			for (j = 1; j < n; j++) {
				if (v[j] < minimo) {
					minimo = v[j];
					imin = j;
				}
			}
			cin >> temp;
			v[imin]+=temp;
		}
		minimo = v[0];
		imin = 0;
		for (j = 1; j < n; j++) {
			if (v[j] < minimo) {
				minimo = v[j];
				imin = j;
			}
		}
		cout << imin +1<< endl;

	}

	return 0;
}
