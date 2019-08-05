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


int main() {
	ios_base::sync_with_stdio(false);
	int i,n;
	lli suma,M,sumaconsecutiva, Mconsecutiva,temp,primero;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}

		cin>>primero;
		suma=M=sumaconsecutiva=Mconsecutiva=primero;

		for(i=1;i<n;++i){
			cin>>temp;
			sumaconsecutiva+=temp;
			if(suma<=0){
				suma=temp;
			}
			else{
				suma+=temp;
			}
			M=max(suma,M);
			Mconsecutiva=max(Mconsecutiva,sumaconsecutiva);

		}
		M=max(M,suma+Mconsecutiva);

		cout<<M<<"\n";

	}
	return 0;
}
