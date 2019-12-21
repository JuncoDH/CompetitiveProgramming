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
	int vida, suma, n, i, villano, inocente;
	pair<pair<int, int>, int> ex;

	while (1) {
		priority_queue<pair<pair<int, int>, int>> q;

		cin >> vida;
		if (!vida) {
			return 0;
		}
		cin >> n;
		suma = 0;
		for (i = 1; i <= n; i++) {
			cin >> inocente >> villano;
			suma += villano;
			q.push(make_pair(make_pair(-inocente, villano), -i));
		}
		if (suma < vida) {
			cout << "MUERTE ESCAPA\n";
			continue;
		}

		ex = q.top();
		q.pop();
		vida -= ex.first.second;
		cout << (-ex.second);
		while (vida > 0) {
			ex = q.top();
			q.pop();
			vida -= ex.first.second;
			cout << " " << (-ex.second);
		}
		cout << endl;
	}
	return 0;
}

