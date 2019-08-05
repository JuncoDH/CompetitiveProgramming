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
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)


#define MAX 1000000000

lli primos[9]={2,3,5,7,11,13,17,19,21},m;


void f(lli num, lli prod, int primo){

	if(prod>MAX||prod<=0||primo>8){
		return;
	}
	int i;
	for(i=2;i<=num;++i){
		if(num%i==0){

			f(num/i,prod*pow(primos[primo],i-1),primo+1);
		}
	}

	if(num!=1){
		return;
	}

	m=min(m,prod);
}


int main() {
	ios_base::sync_with_stdio(false);
	lli n;

	while(1){
		cin>>n;


		if(!n){
			return 0;
		}

		if(n>1350){
			cout<<"+INF\n";
			continue;
		}

		m=LLONG_MAX;

		f(n,1,0);


		if(m==LLONG_MAX||m>MAX){
			cout<<"+INF\n";
			continue;
		}
		cout<<m<<"\n";


	}

	return 0;
}
