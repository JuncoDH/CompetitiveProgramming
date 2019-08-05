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

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(0);
	int  cont;
	unsigned i;
	string s;
	while(1){
		cin>>s;
		if(s[0]=='-'){
			return 0;
		}

		cout<<s[0];
		cont=s[0]-'0';
		for(i=1;i<s.length();++i){
			cout<<" + "<<s[i];
			cont+=s[i]-'0';
		}
		cout<<" = "<<cont<<"\n";
	}
	return 0;
}
