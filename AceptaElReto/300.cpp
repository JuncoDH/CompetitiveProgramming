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
	int casos, z, k, a, e, i, o, u;
	string s;

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		cin >> s;
		a = e = i = o = u = 0;
		for (k = 0; k < s.length(); ++k) {
			if (s[k] == 'a') {
				a = 1;
			} else if (s[k] == 'e') {
				e = 1;
			} else if (s[k] == 'i') {
				i = 1;
			} else if (s[k] == 'o') {
				o = 1;
			} else if (s[k] == 'u') {
				u = 1;
			}

		}

		if (a && e && i && o && u) {
			cout << "SI\n";
		} else {
			cout << "NO\n";
		}

	}
	return 0;
}
