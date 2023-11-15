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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

string s;

int h(){
	int i,n,M=1;
	cin>>n;
	if(!n){
		return 1;
	}
	for(i=0;i<n;++i){
		M=max(h(),M);
	}
	return M+1;

}



int main() {
	ios_base::sync_with_stdio(false);
	int casos,z;

	cin>>casos;
	for(z=0;z<casos;++z){
		cout<<h()<<"\n";

	}


	return 0;
}
