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

#define MOD 46337

int main() {
	ios_base::sync_with_stdio(false);
    long long int i,j,n,p,res,produc;

	while(1){
		cin>>n>>p;
		if(!n&&!p){
			return 0;
		}

		res=0;
		for(i=1;i<=n;++i){
			produc=i;
			for(j=1;j<p;++j){

				produc=(produc*i)%MOD;
			}
			res=(res+produc)%MOD;
		}

	cout<<res<<"\n";

	}

	return 0;
}
