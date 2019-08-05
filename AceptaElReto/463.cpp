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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(false);
	int i, j, x, M;
	string s;
	char c[100][100];

	while (cin >> s) {

		for (i = 0; i < 100; ++i) {
			for (j = 0; j < 100; ++j) {
				c[i][j] = ' ';
			}
		}

		x = s.length();
		M = 0;
		j = 0;
		for (i = 0; i < x; ++i) {
			if (s[i] == 'I') {
				c[i][j] = '_';
				M = max(M, j);
			} else if (s[i] == 'S') {
				c[i][j] = '/';
				M = max(M, j);
				++j;

			} else if (s[i] == 'B') {
				--j;
				c[i][j] = '\\';

			}

		}
		for (i = 0; i < x + 2; ++i) {
			cout << "#";
		}
		cout << endl;
		for (j = M; j >= 0; --j) {
			cout << "#";
			for (i = 0; i < x; ++i) {
				cout << c[i][j];
			}
			cout << "#\n";
		}
		for (i = 0; i < x + 2; ++i) {
			cout << "#";
		}
		cout << endl;

	}
	return 0;
}
