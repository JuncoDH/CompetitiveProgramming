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
	ios_base::sync_with_stdio(0);
	int  cont;
	unsigned i;
	string s;

	while (1) {
		//cin >> s;
		//s="qbfjpvBFJPV";
		getline(cin,s);
		for (i = 1; i < s.length(); ++i) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = (s[i] + 'p' - s[0] - 'a'+26) % 26 + 'a';
			} else if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = (s[i] + 'p' - s[0] - 'A'+26) % 26 + 'A';
			}
		}
		if (s.length() == 4 && s.substr(1, 3) == "FIN") {
			return 0;
		}
		cont = 0;
		for (i = 1; i < s.length(); ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I'	|| s[i] == 'O' || s[i] == 'U') {
				cont++;
			}
		}
		cout << cont << "\n";
	}
	return 0;
}
