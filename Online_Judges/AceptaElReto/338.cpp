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

string s;



int main() {
	ios_base::sync_with_stdio(false);
	int i,temp,n,k,copiados,pillados; //RESIZE

	while(cin>>n){
	vector<int> visitados(100002);
	copiados=0;
	pillados=0;
	cin>>k;
	for(i=0;i<n;++i){
		cin>>temp;
		if(visitados[temp]){
			copiados++;
			if(i+1-visitados[temp]<=k){
				pillados++;
			}
		}

		visitados[temp]=i+1;
	}

	cout<<copiados<<" "<<pillados<<"\n";
	}
	return 0;
}
