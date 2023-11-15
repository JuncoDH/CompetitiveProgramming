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
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

priority_queue<int> p1;
priority_queue<int, vector<int>, greater<int>> p2;

int main() {
	ios_base::sync_with_stdio(false);
	int i,n,temp;
	bool first;

	while(cin>>n){

		p1= priority_queue<int> ();
		p2=priority_queue<int, vector<int>, greater<int>> ();

		first=true;//avoid white space
		for(i=0;i<n;++i){
			cin>>temp;
			if(!temp){
				if(p1.empty()){
					if(first){cout<<"ECSA";}
					else{cout<<" ECSA";}
				}
				else{
					if(first){cout<<p1.top();}
					else{cout<<" "<<p1.top();}
					p1.pop();
				}

				first=false;
			}
			else{
				if(p1.empty()||(!p2.empty()&&temp<p2.top())){
					p1.push(temp);
				}
				else{
					p2.push(temp);
				}
			}

			if(p1.size()>p2.size()+1){
				p2.push(p1.top());
				p1.pop();
			}
			if(p2.size()>p1.size()){
				p1.push(p2.top());
				p2.pop();
			}
			if(!p1.empty()&&!p2.empty()&&p1.top()>p2.top()){
				p1.push(p2.top());
				p2.push(p1.top());
				p1.pop();
				p2.pop();
			}
		}

		cout<<"\n";
	}


	return 0;
}
