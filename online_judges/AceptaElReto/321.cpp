#include <iostream>

using namespace std;

int main() {
	int n, m, z, casos;
	cin >> casos;
	for (z = 0; z < casos; z++) {
		cin >> n >> m;
		cout << (((n + m) * (n + m + 1)) / 2) + 1 + n << endl;
	}
	return 0;
}
