#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#include <string>
#include <utility>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef long long lli;
typedef pair<int,int> ii;

#define pb push_back
#define mp make_pair
#define echo(x) cout<<": "<<x<<endl;

#define MAX 1000000000
vector<int> izq,der;


//el haz izq es x+y y el haz der x-y
int main(void) {
	ios::sync_with_stdio(false);
	int i,n,x,y,M,suma,iz,de;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}

		izq=vector<int>();
		der=vector<int>();

		for(i=0;i<n;++i){
			cin>>x>>y;
			if(x-y<0){
				izq.pb(0);
			}else{
				izq.pb(x-y);
			}

			der.pb(x+y);

		}

		sort(izq.begin(),izq.end());
		sort(der.begin(),der.end());

		M=suma=iz=de=0;

		while(iz<izq.size()){
			for(;de<der.size();++de){
				if(izq[iz]<=der[de]){
					break;
				}
				--suma;
			}
			++suma;
			++iz;
			M=max(M,suma);

		}


		cout<<M<<"\n";
	}
    return 0;
}
