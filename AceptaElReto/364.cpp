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
	int i;
	string s;
	while (1) {
		getline(cin, s);
		if (s == "FIN") {
			return 0;
		}
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == ' ') {
				continue;
			}
			if (s[i] == 'Z') {
				s[i] = 'A';
				continue;
			}
			++s[i];

		}
		cout << s << "\n";

	}

	return 0;
}
