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
	int N, M, i, temp, flag;
	while (cin >> N) {
		cin >> M;
		priority_queue<int> n, m;
		for (i = 0; i < N; ++i) {
			cin >> temp;
			n.push(temp);
		}
		for (i = 0; i < M; ++i) {
			cin >> temp;
			m.push(temp);
		}
		if (M < N) {
			cout << "NO\n";
			continue;
		}
		i = 0;
		flag = 1;
		while (i < N) {
			++i;
			if (n.empty()) {
				flag = 0;
				break;
			}

			if (n.top() <= m.top()) {
				n.pop();
				m.pop();
			} else {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << "SI\n";
		} else {
			cout << "NO\n";
		}

	}

	return 0;
}
