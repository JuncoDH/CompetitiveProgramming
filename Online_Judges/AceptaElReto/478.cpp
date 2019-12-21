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

#define MAX 200005
vector<int> v(MAX);

int main() {
	ios_base::sync_with_stdio(false);
	long long int n, i, suma, total, dif;

	while (1) {
		//cin>>n;
		scanf("%lld", &n);
		if (!n) {
			return 0;
		}
		suma = 0;
		for (i = 0; i < n; ++i) {
			//cin>>v[i];
			scanf("%d", &v[i]);
			suma += v[i];
		}
		scanf("%lld", &total);
		//cin>>total;
		dif = suma - total;
		for (i = 0; i < n; ++i) {
			if (binary_search(v.begin() + i + 1, v.begin() + n, dif - v[i])) {
				printf("%d %lld\n", v[i], dif - v[i]);
				//cout<<v[i]<<" "<<dif-v[i]<<"\n";
				break;
			}
		}

	}
	return 0;
}
