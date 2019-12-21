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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;




int main() {
	ios_base::sync_with_stdio(false);
	int num,z,casos,n,m,r;
	cin>>casos;
	for(z=0;z<casos;z++){
		cin>>n>>m>>r;
		if(r%(n*m)==0){
			cout<<(r/(n*m))<<endl;
		}
		else{
		cout<<(r/(n*m))+1<<endl;
		}
	}

	return 0;
}

