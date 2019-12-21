#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	long long int n, z, tmin, ntmin, tmax, ntmax, temp;

	cin >> n;
	for (z = 0; z < n; z++) {
		ntmin = 0;
		ntmax = 0;
		while (1) {
			cin >> temp;

			if (!temp) {
				break;
			}
			if (!ntmin) {
				tmax = temp;
				tmin = temp;
				ntmin++;
				ntmax++;
				continue;
			}
			if (temp == tmax) {
				ntmax++;
			}
			if (temp == tmin) {
				ntmin++;
			}
			if (temp > tmax) {
				tmax = temp;
				ntmax = 1;

			}
			if (temp < tmin) {
				tmin = temp;
				ntmin = 1;

			}

		}
		cout << tmin << " " << ntmin << " " << tmax << " " << ntmax << endl;
	}
	return 0;
}

