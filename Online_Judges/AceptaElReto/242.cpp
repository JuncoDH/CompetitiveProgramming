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

long long int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n, i,suma,numestudiantes;
	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		suma=0;
		numestudiantes=0;
		for(i=0;i<n;++i){
			cin>>arr[i];
			numestudiantes+=arr[i];
		}
		for(i=0;i<n;++i){
			suma+=arr[i]*(numestudiantes-arr[i]);
		}
		cout<<suma/2<<"\n";


	}

	return 0;
}
