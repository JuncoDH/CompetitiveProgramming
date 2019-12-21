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

#define NUM 22364//95345
long long int triangulares[NUM];

int main() {
	ios_base::sync_with_stdio(false);
	int n,i;



	while (1) {
		cin >> n;
		if(!n){
			return 0;
		}
		for(i=0;i<NUM;++i){
			triangulares[i]=i*(i+1)/2;
					}
		for(i=0;i<NUM;++i){
			if(triangulares[i]>n){
				break;
			}
		}
		cout<<i-1<<" "<<n-triangulares[i-1]<<"\n";

	}

	return 0;
}
