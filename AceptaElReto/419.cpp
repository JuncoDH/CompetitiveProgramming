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

#define echo(x) cout<<":"<<(x);cout<<endl;

vi v(200002); //RESIZE

int main() {
	ios_base::sync_with_stdio(false);

	int n, peso, i, j, cont;

	while (1) {
		cin >> peso >> n;
		if (!peso && !n) {
			return 0;
		}
		cont = 0;
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.begin() + n);
		i = 0;
		j = n - 1;
		while (i <= j) {
			if (v[i] + v[j] <= peso) {
				++i;
				--j;
				++cont;
			} else {
				--j;
				++cont;
			}
		}

		cout << cont << "\n";
	}

	return 0;
}
