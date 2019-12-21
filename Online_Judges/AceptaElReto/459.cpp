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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

char arr[1002][1002];
long long int x, y,i, j, cont, temp;

int main() {
	ios_base::sync_with_stdio(false);


	while (cin >> x) {
		cin >> y;

		for (i = 0; i < y; ++i) {
			for (j = 0; j < x; ++j) {
				cin >> arr[i][j];
			}
		}

		cont = 0;
		for (i = 0; i < y; ++i) {
			for (j = 0; j < x; ++j) {
				temp = 0;
				if (arr[i][j] != '#') {
					continue;
				}

				if ((i+1<y)&&arr[i + 1][j] == '#') {
					++temp;
				}

				if ((i-1>=0)&&arr[i - 1][j] == '#') {
					++temp;
				}
				if ((j+1<x)&&arr[i][j+1] == '#') {
					++temp;
				}
				if ((j-1>=0)&&arr[i][j-1] == '#') {
					++temp;
				}
				if(temp>2){
					cont+=temp;
				}

			}
		}
		cout << cont << "\n";
	}
	return 0;
}
