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

#define echo(x) cout<<":"<<(x)<<endl

//vector<long int> v;
long int v[1000002];

int main() {
	ios_base::sync_with_stdio(false);
	string cosa;
	long int i, j, num, n, n2, inicio;

	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cin >> n2; //PREGUNTAS
		for (i = 0; i < n2; ++i) {
			cin >> cosa >> num;
			if (cosa == "EMBARQUE") {

				for (inicio = 0, j = 0; j < n; ++j) {
					if (v[j] != num) {
						v[inicio] = v[j];
						++inicio;
					}
				}
				n = inicio;
				cout << inicio << "\n";
				continue;
			}

			cout << v[num - 1] << "\n";

		}
		cout << "*\n";

	}

	return 0;
}
