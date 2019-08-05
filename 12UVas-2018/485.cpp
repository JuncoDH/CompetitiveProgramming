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

#define echo(x) cout<<":"<<(x)<<endl


long long int arr[110];

int main() {
	ios_base::sync_with_stdio(false);
	long long int i, suma, n;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		suma=0;
		for(i=0;i<n;++i){
			cin>>arr[i];
			suma+=arr[i];
		}
		cout<<suma;
		suma-=arr[0];
		for(i=1;i<n;++i){
			cout<<" "<<suma;
			suma-=arr[i];
		}
		cout<<"\n";



	}

	return 0;
}