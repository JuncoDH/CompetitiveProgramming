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

	int casos, z, i, p;

	cin >> casos;
	for (z = casos; z; --z) {
		cin >> i >> p;
		p = (p - i + 360) % 360;
		if (p == 0 || p == 180) {
			cout << "DA IGUAL\n";
			continue;
		}

		if (p < 180) {
			cout << "ASCENDENTE\n";
		} else {
			cout << "DESCENDENTE\n";
		}

	}

	return 0;
}
