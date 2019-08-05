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

long int n,sumatotal,arr[1000002],i,sumaizq,difmax,diamax;


int main() {
	ios_base::sync_with_stdio(false);

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		sumatotal=0;
		for(i=0;i<n;++i){
			cin>>arr[i];
			sumatotal+=arr[i];
		}
		if(!sumatotal){
			cout<<"0\n";
			continue;
		}
		difmax=abs(sumatotal);
		diamax=0;
		sumaizq=0;

		for(i=0;i<n;++i){
			sumaizq+=arr[i];
			if(abs(sumatotal-2*sumaizq)<difmax){
				difmax=abs(sumatotal-2*sumaizq);
				diamax=i+1;
			}
		}

		cout<<diamax<<"\n";



	}


	return 0;
}
