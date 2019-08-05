#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 31543

int main() {
	int x, n, i, mult, medio;

	while (1) {
		cin >> x >> n;
		if (!x && !n) {
			return 0;
		}
		mult = 1;
		x %= MOD;
		n %= MOD - 1;
		if (n % 2) {
			for (i = 1; i <= n / 2; i++) {
				mult = (mult * x) % MOD;
			}
			mult = ((mult * mult)%MOD)*x;

		} else {
			for (i = 1; i <= n / 2; i++) {
				mult = (mult * x) % MOD;
			}
			mult = mult * mult;
		}

		mult %= MOD;
		cout << mult << endl;

	}

	return 0;
}
