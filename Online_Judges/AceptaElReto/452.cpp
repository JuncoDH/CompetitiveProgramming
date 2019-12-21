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

#define MAX 2002
int bola[MAX], dif[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	int n, i, j, M;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}

		for (i = 0; i < n; ++i) {
			cin >> bola[i];
		}

		M = bola[0];
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				dif[abs(bola[i] - bola[j])] = 1;
				M = max(M, abs(bola[i] - bola[j]));
			}
		}

		for (i = 1; i <= M; ++i) {
			if (dif[i]) {
				cout << i;
				dif[i] = 0;
				break;
			}
		}

		for (++i; i <= M; ++i) {
			if (dif[i]) {
				cout << " " << i;
				dif[i] = 0;
			}
		}
		cout << "\n";

	}
	return 0;
}
