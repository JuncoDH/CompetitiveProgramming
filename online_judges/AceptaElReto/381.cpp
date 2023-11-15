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
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

lli mcm(lli a, lli b) {
	return a * (b / __gcd(a, b));
}

int main() {
	ios_base::sync_with_stdio(false);
	lli i, n, anterior, temp;
	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		cin >> anterior;
		for (i = 1; i < n; ++i) {
			cin >> temp;
			anterior = mcm(anterior, temp);

		}
		cout << anterior << "\n";
	}

	return 0;
}
