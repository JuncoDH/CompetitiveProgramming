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

int main() {
	ios_base::sync_with_stdio(false);
	lli casos, z, total, suma, cont, i;

	string s;

	cin >> casos;

	for (z = 0; z < casos; ++z) {
		deque<int> d;
		cin >> total >> s;

		cont = 0;
		suma = 0;
		for (i = 0; i < s.length(); ++i) {

			d.push_front(s[i] - '0');
			suma += s[i] - '0';

			while (suma >= total) {

				if (suma == total) {
					++cont;
				}
				suma -= d.back();
				d.pop_back();
			}

		}

		cout << cont << "\n";

	}

	return 0;
}
