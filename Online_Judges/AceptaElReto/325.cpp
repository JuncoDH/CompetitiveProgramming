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
using namespace std;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

vector<char> v(18);

int main() {
	ios_base::sync_with_stdio(false);
	int casos, z, i, n, m;

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		cin >> n >> m;
		for (i = 0; i < n; ++i) {
			v[i] = 'C';
		}
		for (; i < n + m; ++i) {
			v[i] = 'V';
		}

		for (i = 0; i < n + m; ++i) {
			cout << v[i];
		}
		while (next_permutation(v.begin(), v.begin() + n + m)) {
			cout << " ";
			for (i = 0; i < n + m; ++i) {
				cout << v[i];
			}
		}
		cout << "\n";

	}

	return 0;
}
