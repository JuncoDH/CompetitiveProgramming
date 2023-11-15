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
	int i,n,stotal,sactual,igan,pgan,flag,m,arr[300001]; //RESIZE

	while(cin>>n){
	flag=0;
	stotal=0;
	m=9999999;
	for(i=0;i<n;++i){
		cin>>arr[i];
		stotal+=arr[i];
	}
	sactual=0;
	for(i=0;i<n;++i){
		sactual+=arr[i];
		if(abs((stotal-sactual)-sactual)==m){
			flag=1;
		}
		if(abs((stotal-sactual)-sactual)<m){
			m=abs((stotal-sactual)-sactual);
			igan=i+1;
			pgan=sactual;
			flag=0;
		}
	}
	if(flag){
		cout<<"NO JUEGAN\n";
		continue;
	}
	cout<<igan<<" "<<pgan<<" "<<stotal-pgan<<"\n";
	}

	return 0;
}
