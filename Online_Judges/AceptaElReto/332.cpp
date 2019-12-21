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

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	int z, casos, i, suma;
	vector<int> v(10), x(5);

	cin >> casos;

	for (z = casos; z; --z) {
		suma = 0;
		for (i = 0; i < 10; ++i) {
			cin >> v[i];
			suma += v[i];
		}
		suma /= 4; //echo(suma);
		x[2] = suma - v[0] - v[9];
		x[0] = v[1] - x[2];
		x[4] = v[8] - x[2];
		x[1] = v[0] - x[0];
		x[3] = v[9] - x[4];

		cout << x[4];
		for (i = 3; i >= 0; --i) {
			cout << " " << x[i];
		}
		cout << "\n";
	}

	return 0;
}
