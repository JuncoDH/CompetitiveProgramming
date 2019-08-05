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



int i,n,t;
int arr[50005*2];

int calienta(int num){
	priority_queue<int> p;
	int temp;
	for(i=0;i<2*num;i+=2){
		p.push(-(arr[i]+arr[i+1]));
	}
	for(;i<2*n;i+=2){
		temp=-p.top();
		if(temp-arr[i]>t){
			return 0;
		}
		p.pop();
		p.push(-(max(arr[i],temp)+arr[i+1]));

	}


	return 1;

}

int busbin(int izq, int der){
	if(izq+1==der){
		return der;
	}
	if(calienta((izq+der)/2)){
		return busbin(izq, (izq+der)/2);
	}
	else{
		return busbin((izq+der)/2,der);
	}

}

int main() {
	ios_base::sync_with_stdio(false);

	while(1){
		cin>>n>>t;
		if(!n){
			return 0;
		}
		for(i=0;i<2*n;++i){
			cin>>arr[i];
		}

		//for(int k=1;k<n;++k){cout<<k<<": "<<calienta(k)<<"\n";}

		cout<<busbin(0,n)<<"\n";

	}


	return 0;
}
