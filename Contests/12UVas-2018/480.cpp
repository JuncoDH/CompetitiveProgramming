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


int main() {
	ios_base::sync_with_stdio(false);
	long long int casos, z, total, malas, cantidad, totalmalas;

	cin >> casos;
	for (z = casos; z; --z) {
		cin>>total>>malas>>cantidad;
		totalmalas=(total/cantidad) * malas;
		total%=cantidad;

		totalmalas+=min(total, malas);

		cout<<totalmalas<<"\n";

	}

	return 0;
}