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
	int casos, z, arr[7] = { 's', 't', 'a', 'n', 'l', 'e', 'e' }, cont, iarr;
	string s;
	unsigned i;

	//scanf("%d", &casos);
	//getline(cin,s);
	//casos=stoi(s);
	cin >> casos;
	//getchar();
	getline(cin, s);
	for (z = 0; z < casos; ++z) {
		getline(cin, s);

		iarr = 0;
		cont = 0;

		for (i = 0; i < s.length(); ++i) {
			if (s[i] != 's' && s[i] != 't' && s[i] != 'a' && s[i] != 'n'
					&& s[i] != 'l' && s[i] != 'e' && s[i] != 'S' && s[i] != 'T'
					&& s[i] != 'A' && s[i] != 'N' && s[i] != 'L'
					&& s[i] != 'E') {
				continue;
			}
			s[i] = tolower(s[i]);

			if (s[i] == arr[iarr]) {
				if (iarr == 6) {
					iarr = 0;
					++cont;
					continue;
				}
				iarr++;
			}
		}
		cout << cont << endl;

	}

	return 0;
}

