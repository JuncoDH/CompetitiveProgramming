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

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	int i,n,t;

	while(1){
		cin>>n;
		if(n==-1){
			return 0;
		}
		v.push_back(n);
		while(1){
			cin>>n;
			if(n==-1){
				break;
			}
			v.push_back(n);
		}
		cin>>n;
		for(i=0;i<n;++i){
			cin>>t;
			reverse(v.end()-t,v.end());
		}
		cout<<v[v.size()-1]<<endl;
	}


	return 0;
}

