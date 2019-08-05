#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

vector<int> v1(1000000), v2(1000000);

int main() {
	int n, i, j;
	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> v1[i];
			v2[i] = v1[i];
		}

		sort(v2.begin(), v2.begin() + n);
		for (i = 0, j = 0; i < n; i++) {
			if (v1[i] == v2[j]) {
				j++;
			}
		}
		cout << n - j << endl;
	}

	return 0;
}
