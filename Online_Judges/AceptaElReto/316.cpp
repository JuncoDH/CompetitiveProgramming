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

#define MAX 100005
int v[MAX], suma[MAX], L[MAX];
//EN V GUARDAMOS EL INPUT, EN SUMA LA MAYOR SUMA (DP) HASTA EL MOMENTO Y EN LONGITUD LA LONG MINIMA

int main() {
	ios_base::sync_with_stdio(false);
	int n, i, M, l, casos, z;

	cin >> casos;

	for (z = 0; z < casos; ++z) {

		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}

		suma[0] = v[0];
		L[0] = 1;

		for (i = 1; i < n; ++i) {
			if (suma[i - 1] + v[i] > v[i]) {
				L[i] = L[i - 1] + 1;
				suma[i] = suma[i - 1] + v[i];
			} else {
				suma[i] = v[i];
				L[i] = 1;
			}
		}
		M = suma[0];
		for (i = 1; i < n; ++i) {
			M = max(M, suma[i]);
		}
		l = -1;
		for (i = 0; i < n; ++i) {
			if (suma[i] == M) {
				if (l == -1) {
					l = L[i];
					continue;
				}
				l = min(l, L[i]);
			}
		}
		for (i = 0; i < n; ++i) {
			if (suma[i + l - 1] == M && L[i + l - 1] == l) {
				cout << i + 1 << " " << i + l << "\n";
				break;
			}
		}

	}
	return 0;
}
