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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl


int main() {
	ios_base::sync_with_stdio(false);
	int i,j, decimal;
	string s;
	while(cin>>s){
		decimal=0;
		for(i=0;i<s.length();++i){
			if(s[i]!='0'){
				break;
			}
		}

		if(i==s.length()&&s[i-1]=='0'){
			cout<<"0\n";
			continue;
		}

		for(j=0;j<s.length();++j){
			if(s[j]=='.'){
				decimal=1;
				break;
			}
		}
		if(decimal){


		for(j=s.length()-1;j>=0;--j){
			if(s[j]!='0'){
				break;
			}
		}
		if(s[j]=='.'){
			--j;
		}
		}
		else{
			cout<<s.substr(i,s.length()-i)<<"\n";
			continue;
		}

		if(s[i]=='.'){
			cout<<"0"<<s.substr(i,j-i+1)<<"\n";
			continue;
		}

		cout<<s.substr(i,j-i+1)<<"\n";



	}

	return 0;
}