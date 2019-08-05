#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 31543

int main() {

	int ini, fin, n, i, k, num, numM, temp;
	while (1) {
		cin >> ini >> fin >> n;
		num = 0;
		numM = 0;
		if (!ini && !fin && !n) {
			return 0;
		}
		cin >> k;
		for (i = 0; i < k; i++) {
			cin >> temp;
			if (temp == n) {
				num = 1;
			}
			if (temp == n + 1) {
				numM = 1;
			}
		}
		if ((num && numM) || (n == ini && numM) || (n == fin && num)
				|| (ini == fin)) {
			cout << "LO SABE\n";
		} else {
			cout << "NO LO SABE\n";
		}

	}

	return 0;
}
