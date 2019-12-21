#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x)<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int mif(string a, string b) {
	if (a == "2") {
		return 1;
	}
	if (b == "2") {
		return 0;
	}
	if (a == "3") {
		return 1;
	}
	if (b == "3") {
		return 0;
	}
	if (a == "4") {
		return 1;
	}
	if (b == "4") {
		return 0;
	}
	if (a == "5") {
		return 1;
	}
	if (b == "5") {
		return 0;
	}
	if (a == "6") {
		return 1;
	}
	if (b == "6") {
		return 0;
	}
	if (a == "7") {
		return 1;
	}
	if (b == "7") {
		return 0;
	}
	if (a == "8") {
		return 1;
	}
	if (b == "8") {
		return 0;
	}
	if (a == "9") {
		return 1;
	}
	if (b == "9") {
		return 0;
	}
	if (a == "10") {
		return 1;
	}
	if (b == "10") {
		return 0;
	}
	if (a == "J") {
		return 1;
	}
	if (b == "J") {
		return 0;
	}
	if (a == "Q") {
		return 1;
	}
	if (b == "Q") {
		return 0;
	}
	if (a == "K") {
			return 1;
		}
		if (b == "K") {
			return 0;
		}
		return 0;
}

int main() {
	int i, flag;
	char p[5], palo;
	vector<string> c(4);
	map<string, string> mu, mb;
	mu["2"] = "L";
	mu["2"] = "3";
	mu["3"] = "4";
	mu["4"] = "5";
	mu["5"] = "6";
	mu["6"] = "7";
	mu["7"] = "8";
	mu["8"] = "9";
	mu["9"] = "10";
	mu["10"] = "J";
	mu["J"] = "Q";
	mu["Q"] = "K";
	mu["K"] = "A";
	mb["A"] = "K";
	mb["3"] = "2";
	mb["4"] = "3";
	mb["5"] = "4";
	mb["6"] = "5";
	mb["7"] = "6";
	mb["8"] = "7";
	mb["9"] = "8";
	mb["10"] = "9";
	mb["J"] = "10";
	mb["Q"] = "J";
	mb["K"] = "Q";
	mb["2"] = "LL";
	while (1) {
		flag = 0;
		cin >> c[0];

		if (c[0] == "0") {
			return 0;
		}
		cin >> palo;
		for (i = 1; i < 4; i++) {
			cin >> c[i] >> p[i];
			if (p[i] != palo||(palo!='P'&&palo!='D'&&palo!='T'&&palo!='C')) {
				flag = 1;
			}
		}
		sort(c.begin(), c.end(), mif);

		if (flag||c[0]==c[1]||c[1]==c[2]||c[2]==c[3]) {
			cout << "NADA\n";
			continue;
		}

		if (c[0] == mb[c[1]] && c[1] == mb[c[2]] && c[2] == mb[c[3]]) {
			if (c[3] != "") {
				cout << mu[c[3]] << " " << palo << endl;
			} else {
				cout << mb[c[0]] << " " << palo << endl;
			}
		} else if (c[0] == mb[mb[c[1]]] && c[1] == mb[c[2]]
				&& c[2] == mb[c[3]]) {
			cout << mb[c[1]] << " " << palo << endl;
		} else if (c[0] == mb[c[1]] && c[1] == mb[mb[c[2]]]
				&& c[2] == mb[c[3]]) {
			cout << mb[c[2]] << " " << palo << endl;
		} else if (c[0] == mb[c[1]] && c[1] == mb[c[2]]
				&& c[2] == mb[mb[c[3]]]) {
			cout << mb[c[3]] << " " << palo << endl;
		} else {
			cout << "NADA\n";
		}

	}
	return 0;
}

