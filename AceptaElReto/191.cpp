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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int main() {
	ios_base::sync_with_stdio(false);
	int casos, z, n, max, dif, total, i;

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		cin >> n >> max >> dif;
		total = 0;
		for (i = 0; i < n; ++i) {
			total += max;
			max -= dif;
		}
		cout << total << "\n";

	}
	return 0;
}
