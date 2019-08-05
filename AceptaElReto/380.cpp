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
	int n, i, total, temp;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		total = 0;
		for (i = n; i; --i) {
			cin >> temp;
			total += temp;
		}
		cout << total << "\n";

	}
	return 0;
}
