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

long long int n,arr[55];

long long int f(int num){

	if(arr[num]){
		return arr[num];
	}

	return arr[num]=f(num-1)+f(num-2);
}


int main() {
	ios_base::sync_with_stdio(false);
	arr[1]=1;
	arr[2]=2;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}

		cout<<f(n)<<"\n";

	}


	return 0;
}
