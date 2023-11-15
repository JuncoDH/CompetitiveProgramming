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
	int i,n,num,flag;
	string nombre;

while(1){
	vector<string> v(27);
	cin>>n;
	if(!n){
		return 0;
	}
	flag=0;
	for(i=1;i<=n;++i){
		cin>>num;
		getline(cin,nombre);
		if(flag||i+num>26||i+num<1||v[i+num]!=""){
			flag=1;
			continue;
		}
		v[i+num]=nombre;
	}
	if(flag){
		cout<<"IMPOSIBLE\n-----\n";
		continue;
	}
	for(i=1;i<=26;++i){
		if(v[i]!=""){
			cout<<i<<v[i]<<"\n";
		}
	}
	cout<<"-----\n";
}
	return 0;
}
