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
	ios_base::sync_with_stdio(0);
	int n, temp, cont, M, pk, imax;
	while (1) {
		cin >> n;
		if (n == -1) {
			return 0;
		}
		cont = 1;
		M = -1;
		pk = 1;
		temp = n;
		imax = 0;
		while (1) {
			cin >> n;
			if (n == -1) {
				break;
			}
			pk++;
			if (n == temp) {
				cont++;
				if (cont > M) {
					M = cont;
					imax = pk - cont;
				}
			} else {
				cont = 1;
				temp = n;
			}

		}
		if (M == -1) {
			cout << "HOY NO COMEN\n";
			continue;
		}
		cout << imax << " " << M - 1 << endl;

	}
	return 0;

}
