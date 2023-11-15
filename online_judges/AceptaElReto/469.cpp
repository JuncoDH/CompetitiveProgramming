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
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int main() {
	ios_base::sync_with_stdio(false);
	lli n, i;
	string s;
	vi izq, der;

	while (cin>>n) {

		if(!n){
			cout<<"0 ==X== patatas\n";
			continue;
		}

		s = "";
		izq = vi();
		der = vi();
		while (n) {
			s += to_string(n % 3);
			n /= 3;
		}

		//0 pasa, 1 pone 3^i en la izq, y si hay 2 pone 3^i en la der y suma 1 (completar los multiplos de 3)
		
		for (i = 0; i < s.length(); ++i) {
			if (s[i] == '0') {
				continue;
			}
			if (s[i] == '1') {
				izq.pb(i);
				continue;
			}

			if (s[i] == '3') { //nos hemos llevado 1 y este es un 2, ponemos 0 y llevamos 1
				if (i == s.length() - 1) {
					s += "1";
					continue;
				}
				++s[i + 1];
				continue;
			}
			der.pb(i);
			if (i == s.length() - 1) {
				s += "1";
				continue;
			}
			++s[i + 1];

		}
		for (i = 0; i < izq.size(); ++i) {
			cout << (lli)pow(3, izq[i]) << " ";
		}
		cout << "==X== ";
		for (i = 0; i < der.size(); ++i) {
			cout << (lli)pow(3, der[i]) << " ";
		}
		cout << "patatas\n";

	}
	return 0;
}
