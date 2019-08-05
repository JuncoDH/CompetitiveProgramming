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

int main() {
	ios_base::sync_with_stdio(false);

	int total;
	string s;
	unsigned i;
	char a;

	while (cin >> s) {
		stack<char> c;
		if (s == "") {
			return 0;
		}
		total = 0;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == 'R' || s[i] == 'A') {
				c.push(s[i]);
				continue;
			}
			if (c.size() < 2) {
				c.push(s[i]);
				continue;
			}
			a = c.top();
			c.pop();
			if (a == 'A' && c.top() == 'R') {
				c.pop();
				++total;
				continue;
			}
			c = stack<char>(); //SI HAY UN V ESE NO SE VA A PODER FORMAR NUNCA

		}
		cout << total << "\n";

	}

	return 0;
}
