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

int arr[20001];

void f(int n){
	//cout<<n<<endl;
	if(n>20001){
		return;
	}
	if(arr[n]){
		return;
	}
	arr[n]=1;

	f(n+5);
	f(n*3);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	f(1);

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		if(arr[n]){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}

	}

	return 0;
}
