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
	int casos, z, n1, n2, i;
	string s;

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		queue<pair<int, pair<string, int>>> q;
		map<int, int> m;
		i = 1;

		while (1) {
			cin >> n1;
			if (!n1) {
				break;
			}
			m[n1] = i * 10;
			++i;

			cin >> s;
			n2 = -1; //para el return
			if (s != "RETURN") {
				cin >> n2;
			}
			q.push(make_pair(n1, make_pair(s, n2)));

		}
		while (i > 1) {
			if (q.front().second.second == -1) {
				cout << m[q.front().first] << " " << q.front().second.first
						<< "\n";
			} else {
				cout << m[q.front().first] << " " << q.front().second.first
						<< " " << m[q.front().second.second] << "\n";
			}
			q.pop();
			--i;

		}
		cout << "---\n";
	}

	return 0;
}
