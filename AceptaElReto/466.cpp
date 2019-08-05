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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define NUM 22364//95345
long long int triangulares[NUM];

int main() {
	ios_base::sync_with_stdio(false);
	int z, casos, i, llevo, n;
	string s, s1, s2;

	cin >> casos;
	for (z = casos; z; --z) {
		cin >> s1 >> s2;

		while (s1.length() > s2.length()) {
			s2 = "0" + s2;
		}
		while (s1.length() < s2.length()) {
			s1 = "0" + s1;
		}
		s1 = "0" + s1;
		s2 = "0" + s2;
		llevo = 0;
		s = "";
		for (i = s1.length() - 1; i >= 0; --i) {
			n = ((s1[i] - '0') * (s2[i] - '0') + llevo);
			llevo = 0;
			while (n > 9) {
				llevo += 1;
				n -= 10;
			}
			s = to_string(n) + s;
		}

		if (s[0] == '0') {
			cout << s.substr(1, s.length() - 1) << "\n";
		} else {
			cout << s << "\n";
		}

	}

	return 0;
}
