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

int main() {
	int n, k, m;
	while (1) {
		cin >> n >> k;
		if(!n&&!k){
			return 0;
		}

		m=((n * (n + 1)) / 2)+k-1;

		cout << (((m * (m + 1)) / 2) - (((m - n) * (m - n+1)) / 2))<<endl;

}
return 0;
}

