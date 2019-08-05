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
#include <time.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	int i, iarr, flag;
	while (1) {
		getline(cin, s);
		if (s == "XXX") {
			return 0;
		}
		iarr = 0;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] != ' ') {
				s[iarr] = tolower(s[i]);
				++iarr;
			}
		}
		flag = 0;
		for (i = 0; i < iarr / 2; ++i) {
			if (s[i] != s[iarr - i - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			printf("NO\n");
		} else {
			printf("SI\n");
		}

	}

	return 0;
}

