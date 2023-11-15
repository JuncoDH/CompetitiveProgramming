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
	long long int n, i, temp;
	vector<long long int> m(2), M(2);
	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		cin >> temp;
		m[0] = temp;
		M[0] = temp;
		cin >> temp;
		m[1] = temp;
		M[1] = temp;
		for (i = 2; i < n; i++) {
			sort(m.begin(), m.end());
			sort(M.begin(), M.end());
			cin >> temp;
			M[0] = max(M[0], temp);
			m[1] = min(m[1], temp);
		}
		//echo(m[0]);echo(m[1]);echo(M[0]);echo(M[1]);
		cout << max(m[0] * m[1], M[0] * M[1]) << endl;

	}

	return 0;
}

