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
	unsigned i;
	string s, s2, temp;

	while (cin >> s) {
		for (i = 0; i < s.length(); ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = s[i] - 'a' + 'A';
			}
		}
		for (i = 0; i < s.length(); ++i) {
			temp = s.substr(0, i + 1);
			s2 = temp;
			while (s2.length() < s.length()) {
				s2 += temp;
			}
			if (s2 == s) {
				break;
			}
		}
		cout << i + 1 << "\n";
	}

	return 0;
}
