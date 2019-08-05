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

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int arr[250001], arr2[250001];

int main() {
	ios_base::sync_with_stdio(false);
	int i, n;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; i++) {
			cin >> arr[i];
			arr2[i] = 0;
		}
		for (i = n - 1; i > 0; --i) {
			if ( i + arr[i] == n - 1||((i+arr[i]+1)<n&&arr2[i+arr[i]+1])) {
				arr2[i] = 1;
			}
		}


		for (i = 0; i < n; i++) {
			if (arr2[i]) {
				break;
			}
		}
		cout << i << endl;
	}
	return 0;
}