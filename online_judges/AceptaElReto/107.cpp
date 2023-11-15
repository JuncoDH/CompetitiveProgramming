#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<x<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}

#define NUM_PRIM 9600

vi primos(NUM_PRIM);

void rellenarPrimos() {
	int i, p = 1, flag, j;
	primos[0] = 2;
	for (i = 3; i < 100000; i += 2) {
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
			if (p > NUM_PRIM) {
				return;
			}
		}
	}
}

int main() {
	int m;
	double error1, error2, n;
	rellenarPrimos();

	vector<int>::iterator low;

	while (1) {
		cin >> n >> m;

		if (!n && !m) {
			return 0;
		}
		low = lower_bound(primos.begin(), primos.end(), n);
		if (n == 1) {
			cout << "Igual\n";
			continue;
		}
		if (n == primos[(low - primos.begin())]) {
			error1 = (((low - primos.begin()) + 1) / n) - 1 / log(n);
		} else {
			error1 = (((low - primos.begin())) / n) - 1 / log(n);
		}

		error2 = 1 / pow(10, m);

		if (abs(error1) > error2) {
			cout << "Mayor\n";
		} else if (abs(error1 == error2)) {
			cout << "Igual\n";
		} else {
			cout << "Menor\n";
		}

	}

	return 0;
}

