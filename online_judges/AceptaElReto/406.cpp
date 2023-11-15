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
	string s, final, temp, tempPuntos;
	int i, flag, num, n;
	while (cin >> s) {
		final = "";
		temp = "";
		tempPuntos = "";
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == '|') {
				final += tempPuntos + temp + "|";
				tempPuntos = "";
				temp = "";
				continue;
			}
			if (s[i] == '.') {
				tempPuntos += '.';
				continue;
			}
			temp += s[i];

		}
		flag = 0;
		for (i = s.length() - 1; i >= 0; --i) {
			if (s[i] == '|') {
				flag = 1;
				break;
			}
		}
		if (flag || i == -1) { //PONE PUNTOS A TODAS POSICIONES QUE NO TIENEN DELANTE UN SEMAFORO
			for (++i; i < s.length(); ++i) {
				final += ".";
			}
		}
		cin >> n;
		if (n) {
			cin >> num;
			cout << final[num - 1];
		}
		for (i = 1; i < n; ++i) {
			cin >> num;
			cout << " " << final[num - 1];
		}
		cout << "\n";

	}

	return 0;
}
