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
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
string s, r;
int casos, z, i;

int main() {
	ios_base::sync_with_stdio(false);

	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>s>>r;
		for(i=0;i<s.length();++i){
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
				s[i]='2';
			}
		}
		for(i=0;i<r.length();++i){
			if(r[i]=='a'||r[i]=='e'||r[i]=='i'||r[i]=='o'||r[i]=='u'){
				r[i]='2';
			}
		}
		if(s==r){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}


	}



	return 0;
}
