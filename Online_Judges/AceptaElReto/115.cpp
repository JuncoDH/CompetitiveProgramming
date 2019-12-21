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
	int i, j, flag;
	long long int n, m;
	string s;

	while (1) {
		cin >> n;
		//n=1234;
		if (!n) {
			return 0;
		}
		if (n == 1) {
			cout << "SI\n";
			continue;
		}

		m = n * n;
		s = to_string(m); //echo(s);
		flag = 0;
		for (i = 0; i < s.length() - 1; ++i) {
			//cout<<stoi(s.substr(0,i+1))<<" "<<stoi(s.substr(i+1,s.length()-i))<<endl;
			if (stoi(s.substr(i + 1, s.length() - i)) == 0) {
				continue;
			}
			if (stoi(s.substr(0, i + 1)) + stoi(s.substr(i + 1, s.length() - i))
					== n) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "SI\n";
		} else {
			cout << "NO\n";
		}

	}

	return 0;
}
