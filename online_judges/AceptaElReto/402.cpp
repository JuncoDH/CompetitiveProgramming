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
	int i, n;
	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		for(i=sqrt(n);i>=1;--i){
			if(n%i==0){
				cout<<n/i<<"\n";
				break;
			}
		}


	}

	return 0;
}
