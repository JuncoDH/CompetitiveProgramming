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

int main() {
	ios_base::sync_with_stdio(false);

	int i,n,flag;
	string s;

	while (1) {
		cin>>n;
		if(!n){
			return 0;
		}
		set<string> m;
		flag=0;
		for(i=0;i<n;++i){
			cin>>s;
			if(flag){
				continue;
			}
			s=s.substr(0,s.length()-4);
			if(m.find(s)!=m.end()){
				flag=1;
			}
			else{
				m.insert(s);
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
