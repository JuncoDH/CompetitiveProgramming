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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_array(x,y) for(i=0;i<y;++i){for(j=0;j<x;++j){	cout<<arr[i][j]<<" ";}cout<<endl;}

int main() {
	ios_base::sync_with_stdio(false);

	int x, y, i, j, k, cambios, flag;
	char arr[52][52]; //RESIZE

	while (cin >> x) {
		cin >> y;
		for (i = 0; i < y; ++i) {
			for (j = 0; j < x; ++j) {
				cin >> arr[i][j];
			}
		}
		for (i = 0; i < y; ++i) {
			arr[i][0] = 'L';
			arr[i][x - 1] = 'L';
		}
		for (j = 0; j < x; ++j) {
			arr[0][j] = 'L';
			arr[y - 1][j] = 'L';
		}
		cambios = 1;
		while (cambios) {
			cambios = 0;
			for (i = 0; i < y; ++i) {
				for (j = 0; j < x; ++j) {
					if (arr[i][j] == 'L' || arr[i][j] == 'X') {
						continue;
					}
					for (k = j - 1; k >= 0; --k) { //izq
						if (arr[i][k] == 'L') {
							arr[i][j] = 'L';
							cambios = 1;
							break;
						}
						if (arr[i][k] == 'X') {
							break;
						}
					}

					for (k = j + 1; k < x; ++k) { //der
						if (arr[i][k] == 'L') {
							arr[i][j] = 'L';
							cambios = 1;
							break;
						}
						if (arr[i][k] == 'X') {
							break;
						}
					}

					for (k = i - 1; k >= 0; --k) { //arriba
						if (arr[k][j] == 'L') {
							arr[i][j] = 'L';
							cambios = 1;
							break;
						}
						if (arr[k][j] == 'X') {
							break;
						}
					}

					for (k = i + 1; k < y; ++k) { //abajo

						if (arr[k][j] == 'L') {
							arr[i][j] = 'L';
							cambios = 1;
							break;
						}
						if (arr[k][j] == 'X') {
							break;
						}
					}

				}
			}
		}
		//echo_array(x, y);
		flag = 0;
		for (i = 0; i < y; ++i) {
			for (j = 0; j < x; ++j) {
				if (arr[i][j] == '.') {
					flag = 1;
					i = y;
					break;
				}
			}
		}

		if (flag) {
			cout << "SI\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
