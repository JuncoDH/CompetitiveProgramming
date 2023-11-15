#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	long long int x, n, i, suma, base;

	while (cin >> x) {
		cin >> n;
		suma = 1 + x;
		base = x;
		if (!x) {
			cout << "0\n";
			continue;
		}
		if(!n){
			cout<<"1\n";
			continue;
		}
		if (n == 1) {
			cout << suma << endl;
			continue;
		}
		for (i = 2; i <= n; i++) {
			suma += (base * x) % 1000007;
			x = (x * base) % 1000007;

		}
		cout << (suma % 1000007) << endl;
	}
/*48568*/
	return 0;
}
