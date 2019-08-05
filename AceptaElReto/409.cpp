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
	ios_base::sync_with_stdio(false);
	int p, q, i, cont, z, casos;
	vector<int> v(101);

	cin >> casos;
	for (z = 0; z < casos; ++z) {
		cont = 0;
		cin >> p >> q;
		for (i = 0; i < q; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.begin() + q);

		for (i = 0; i <= q - p; ++i) {
			if (v[i + p - 1] - v[i] <= 15) {
				cont++;
				i += p - 1;
			}
		}
		cout << cont << "\n";
	}
	return 0;
}
