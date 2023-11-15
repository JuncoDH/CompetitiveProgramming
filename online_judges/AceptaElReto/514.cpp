#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>
#include <fstream>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 300005
vi v(MAX), res(MAX);
stack<pii> s;

ll n, i,j;

int main(){
    ios::sync_with_stdio(false);

    while(1){
    	cin>>n;
    	if(!n)return 0;

    	s=stack<pii>();
    	for(i=0;i<n;++i)cin>>v[i];

    	for(i=n-1;i>=0;--i){
			while(!s.empty()&&s.top().fi>=v[i]){
				res[s.top().se]=s.top().se-i-1;
				s.pop();
    		}

    		s.push(mp(v[i], i));
    	}

    	while(!s.empty()){
    		res[s.top().se]=s.top().se;
    		s.pop();
    	}

    	cout<<res[0];
    	for(i=1;i<n;++i)cout<<" "<<res[i];

    	cout<<"\n";


    }
    return 0;
}