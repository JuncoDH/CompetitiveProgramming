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
#include <time.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 200005
vector<int> v1(MAX), v2(MAX);

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	int i, n, suma;
	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; ++i) {
			cin >> v1[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> v2[i];
		}
		sort(v1.begin(), v1.begin() + n);
		sort(v2.begin(), v2.begin() + n);
		suma = 0;
		for (i = 0; i < n; ++i) {
			suma += abs(v1[i] - v2[i]);
		}
		cout << suma << "\n";
	}

	return 0;
}

