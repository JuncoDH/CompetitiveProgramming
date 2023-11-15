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
	int n,i,j,flag;
	string s;


	while (1) {
		cin >> n;
		if (!n) {
			return 0;
		}
		flag=0;
		cin>>s;

		for(i=0;i<s.length();++i){
			if(s[i]=='.'){
				continue;
			}
			for(j=i;j<s.length();++j){
				if(s[j]!='.'&&s[j]!=s[i]){
					flag=1;
					break;
				}
			}
			break;
		}

		if(flag){

			cout<<"ALGUNO NO COME\n";
			continue;
		}
		cout<<"TODOS COMEN\n";
	}

	return 0;
}
