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
	ios_base::sync_with_stdio(false);
	int  z, casos;
	string s;
	unsigned i,cont;

	cin >> casos;
	//casos=1;
	for (z = 0; z < casos; ++z) {
		cin>>s;

		cont=0;
		i = 0;
		do {
			i+=(s[i]-'0');
			i%=(s.length());
			cont++;
			//echo(i);


		}while(i!=0&&cont<s.length());

		if(cont==s.length()&&i==0){
			cout<<"SALTARINES\n";
		}
		else{
			cout<<"NORMALES\n";
		}
	}
	return 0;
}
