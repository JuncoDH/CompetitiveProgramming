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

int umbral, uvas, i, total;
vector<int> v(28);

void eleccion(int nueva, int suma, int in) {
	if (nueva == 12 && suma <= umbral) {
		++total;
		return;
	}
	if (suma > umbral || (in + nueva) < 0 || in < 0) {
		return;
	}
	eleccion(nueva + 1, suma + v[in], in - 1); //COGE UVA
	eleccion(nueva, suma, in - 1);   	       //NO COGE UVA
}

int main() {
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> umbral >> uvas;
		if (!umbral && !uvas) {
			return 0;
		}
		total = 0;
		for (i = 0; i < uvas; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.begin() + uvas);
		eleccion(0, 0, uvas - 1);

		cout << total << "\n";

	}

	return 0;
}
