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

int arr[101][101];

int llena(int b, int p) {
	int i;
	queue<int> q;
	for (i = 1; i <= b; ++i) {
		q.push(i);
	}
	while (q.size() != 1) {
		for (i = 1; i < p; ++i) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	return q.front();
}

int main() {
	ios_base::sync_with_stdio(false);

	int b, p;

	while (1) {
		cin >> b >> p;
		if (!b && !p) {
			return 0;
		}
		if (!arr[b][p]) {
			arr[b][p] = llena(b, p);
		}
		cout << arr[b][p] << "\n";

	}

	return 0;
}
