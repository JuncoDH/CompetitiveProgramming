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



int main() {
	ios_base::sync_with_stdio(false);
    int n,i;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		if(n==1){
			cout<<"10\n";
			continue;
		}
		cout<<"9";
		if(n%2){
			for(i=1;i<(n+1)/2;++i){
				cout<<"0";
			}
			cout<<"\n";
			continue;
		}
		for(i=0;i<(n/2)-1;++i){
			cout<<"0";
		}
		cout<<"\n";


	}






	return 0;
}
