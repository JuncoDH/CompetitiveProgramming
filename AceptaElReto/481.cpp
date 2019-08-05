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


int main() {
	ios_base::sync_with_stdio(false);
	map<int, char> m;
	m[1]='h';
	m[2]='g';
	m[3]='f';
	m[4]='e';
	m[5]='d';
	m[6]='c';
	m[7]='b';
	m[8]='a';

	int x, y;

	while (1) {
		cin>>x>>y;
		if(!x&&!y){
			return 0;
		}

		cout<<m[x]<<y<<"\n";

	}

	return 0;
}