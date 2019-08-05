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

long long int casos, z, n, suma,veces;

int main() {
	//ios_base::sync_with_stdio(false);


	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>n;
		suma=n;
		while(n>=3600){
			veces=n/3600;
			suma+=veces;
			n=n-veces*3600+veces;
		}
		cout<<suma<<"\n";

	}

	return 0;
}