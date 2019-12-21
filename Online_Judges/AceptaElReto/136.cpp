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

int f(int h, int cad) {
	if (cad <= 2 * h) {
		return 0;
	}
	return f(h, cad / 3) + f(h, cad - cad / 3) + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	while (1) {

		cin >> n >> m;

		if (!n) {
			return 0;
		}
		cout << f(n, m) << endl;
	}

	return 0;
}

