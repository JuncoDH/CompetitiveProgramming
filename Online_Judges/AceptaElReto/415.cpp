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

	lli n;

	while (1) {
		cin>>n;
		if(!n){
			return 0;
		}
		if(n%9==0){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}

	}

	return 0;
}
