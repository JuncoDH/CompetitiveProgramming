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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(false);
	int n,m,i;
	long long res;


	while (1) {
		cin >> n>>m;
		if(m>n){
			return 0;
		}
		res=1;
		for(i=m+1;i<=n;++i){
			res*=i;
		}
		cout<<res<<"\n";

	}

	return 0;
}
