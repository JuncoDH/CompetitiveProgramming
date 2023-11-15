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

long int cod[102], v[102];

int main() {
	ios_base::sync_with_stdio(false);
	long int n, i, j, cont;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 1; i <= n; ++i) {
			cin >> cod[i]; //es la codificacion
		}

		for (i = 1; i <= n; ++i) {
			cont = 1;
			j = i;
			while (cod[j] != i) {
				j = cod[j];
				++cont;
			}
			v[i] = cont;
		}
		cont = 1;
		for (i = 1; i <= n; ++i) {
			cont *= (v[i] / __gcd(cont, v[i]));
		}

		cout << cont << "\n";

	}

	return 0;
}
