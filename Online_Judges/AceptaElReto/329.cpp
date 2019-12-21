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
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int main() {
	ios_base::sync_with_stdio(false);
	int n, izq, der, i, cont, M;
	priority_queue<ii> p;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		p = priority_queue<ii>();
		M = -1;
		cont = 0;

		for (i = 0; i < n; ++i) {
			cin >> izq >> der;
			++izq; //para casar los bordes del edificio con los huecos en el array
			p.push(mp(-der, izq));
		}
		while (!p.empty()) {

			if (p.top().second > M) {
				M = -p.top().first;
				++cont;
			}
			p.pop();
		}

		cout << cont << "\n";

	}

	return 0;
}
