#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl

long long int primos[4900];

void rellenarPrimos() {
	int i, p = 1, flag, j;
	primos[0] = 2;
	for (i = 3; i < 47000; i += 2) {
		flag = 1;
		for (j = 0; j < p; j++) {
			if (i % primos[j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			primos[p] = i;
			p++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli casos, z, n, i, m;
	rellenarPrimos();

	cin >> casos;
	for (z = casos; z; --z) {
		cin >> n;
		m = sqrt(n);
		if (m * m == n) {
			cout << "1\n";
			continue;
		}
		for (i = 0; primos[i] <= m; ++i) {
			if (n % (primos[i] * primos[i]) == 0) {
				n /= (primos[i] * primos[i]);
				--i;
				m = sqrt(n);
			}
		}
		cout << n << "\n";
	}

	return 0;
}
