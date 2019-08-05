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

#define echo(x) cout<<":"<<(x)<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	int i,n,m,casos,z;
	cin>>casos;
	for(z=0;z<casos;++z){
	cin>>n;
	for(i=1;i<n;++i){
		m=sqrt(n*n-i*i);
		if(m*m+i*i==n*n){
			break;
		}
	}
	cout<<i+m<<"\n";
	}
	return 0;
}
