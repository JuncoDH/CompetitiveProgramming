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

int capicua(int i, int j){
	if(i>j){
		return 0;
	}
	//echo(i);echo(j);
	if(s[i]=='0'&&i!=j){
		return 0;
	}
	int k;
	for(k=i;k<j;++k){
		if(s[k]!=s[j-k+i]){
			return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int i,flag;

	/*while(1){
		cin>>s;
		cout<<capicua(0,1)<<endl<<capicua(2,4);
	}*/

	while(1){
		cin >>s;
		if(s=="0"){
			return 0;
		}
		if(s.length()==1){
			cout<<"NO\n";
			continue;
		}

		flag=0;
		for(i=0;i<s.length();++i){
			if(capicua(0,i)&&capicua(i+1,s.length()-1)){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}
