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
	int  i,flag;
	string s;

	while(1){
		cin>>s;
		if(s[0]=='-'){
			return 0;
		}
		flag=0;
		for(i=0;i<s.length();++i){
			if((s[i]-'0')%2==1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO\n";
		}
		else{
			cout<<"SI\n";
		}

	}
	return 0;
}
