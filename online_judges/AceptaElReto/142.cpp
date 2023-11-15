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

#define echo(x) cout<<":"<<(x)<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 10000 //RESIZE
int arr[MAX];

int main() {
	int i, n, s, j, temp;

	while (1) {
		cin >> n >> s;
		//n=5;s=1;
		if (!n && !s) {
			return 0;
		}
		if (!s) {
			cout << n << endl;
			continue;
		}

		for (i = 1; i <= n; i++) {
			arr[i] = (i % n) + 1;
		}

		i = 1;
		while (arr[i] != i) {
			for (j = 0; j < s; j++) {
				temp = i;
				i = arr[i];
			}
			arr[temp] = arr[i];
			i = arr[i];
		}
		cout << i << endl;
	}
	return 0;
}

