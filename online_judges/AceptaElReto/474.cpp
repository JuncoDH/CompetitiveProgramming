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

int main() {
	ios_base::sync_with_stdio(false);
	int s, a, b, casos, z;
	cin >> casos;
	for (z = 0; z < casos; z++) {
		cin >> s >> a >> b;
		if (a > b) {
			b ^= a;
			a ^= b;
			b ^= a;
		}
		if (s == a && s == b) {
			cout << "0\n";
			continue;
		}
		if (s == a) {
			cout << b - s << endl;
			continue;
		}
		if (s == b) {
			cout << s - a << endl;
			continue;
		}
		if (s > a && s > b) {
			cout << s - a << endl;
			continue;
		} else if (s < a && s < b) {
			cout << b - s << endl;
			continue;
		}
		cout << 2 * min(abs(b - s), abs(a - s)) + max(abs(s - a), abs(s - b))
				<< endl;
	}

	return 0;
}

