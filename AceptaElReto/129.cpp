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

#define echo(x) cout<<":"<<x<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}

typedef struct {
	int a, b, c, d, e, f, g;

} numero;

int main() {
	numero n[11] = { { 1, 1, 1, 0, 1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 0 }, { 1, 0,
			1, 1, 1, 0, 1 }, { 1, 0, 1, 1, 0, 1, 1 }, { 0, 1, 1, 1, 0, 1, 0 }, {
			1, 1, 0, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1, 1, 1 }, { 1, 0, 1, 0, 0, 1,
			0 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 0, 1, 1 }, { 0, 0, 0, 0,
			0, 0, 0 } };

	int cont, suma, temp, num, entra;

	suma = 0;
	cont = 0;
	temp = 10;
	entra = 0;
	while (cin >> num) {
		if (num == -1 && !entra) {
			return 0;
		}
		if (num == -1 && entra) {
			suma += (n[10].a ^ n[temp].a) + (n[10].b ^ n[temp].b)
					+ (n[10].c ^ n[temp].c) + (n[10].d ^ n[temp].d)
					+ (n[10].e ^ n[temp].e) + (n[10].f ^ n[temp].f)
					+ (n[10].g ^ n[temp].g);
			cout << (suma * cont) << endl;
			suma = 0;
			cont = 0;
			temp = 10;
			entra = 0;
			continue;
		}
		cont++;
		suma += (n[num].a ^ n[temp].a) + (n[num].b ^ n[temp].b)
				+ (n[num].c ^ n[temp].c) + (n[num].d ^ n[temp].d)
				+ (n[num].e ^ n[temp].e) + (n[num].f ^ n[temp].f)
				+ (n[num].g ^ n[temp].g);
		temp = num;
		entra = 1;
	}
	return 0;
}

