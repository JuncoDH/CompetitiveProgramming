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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(false);
	int parejas;
	unsigned i;
	char c;
	string s;
	while (cin >> s) {
		stack<char> q;
		parejas = 0;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == '@') {
				q = stack<char>();
				continue;
			}
			if (s[i] == 'h' || s[i] == 'H') {
				q.push(s[i]);
				continue;
			}

			if (q.empty()) {
				continue;
			}
			c = q.top();
			if (s[i] == 'm' && c == 'h') {
				q.pop();
				++parejas;
				continue;
			}
			if (s[i] == 'M' && c == 'H') {
				q.pop();
				++parejas;
				continue;
			}
			if (s[i] == 'm' && c == 'H') {
				q = stack<char>();
				continue;
			}
			if (s[i] == 'M' && c == 'h') {
				q = stack<char>();
				continue;
			}
		}
		cout << parejas << endl;
	}

	return 0;
}

