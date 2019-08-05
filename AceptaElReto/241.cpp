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
	int n,z,casos;
	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>n;
		if(n==1||n==2||n==5){
			cout<<"IMPOSIBLE\n";
			continue;
		}
		if(n%3==0){
			cout<<"0\n";
			continue;
		}
		if(n%3==1){
			cout<<"1\n";
			continue;
		}
		if(n%3==2){
			cout<<"2\n";
			continue;
		}

	}

	return 0;
}
