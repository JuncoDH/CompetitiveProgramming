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


typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll a, b, i, j;
#define MAX 30005
queue<pair<ll,ll>> qa, qb;
pair<ll,ll> par;
ll res;

int main(){
    ios::sync_with_stdio(false);

    while(cin>>a){
    	cin>>b;

    	qa=queue<pair<ll,ll>>();
    	qb=queue<pair<ll,ll>>();
    	res=0;

    	for(i=0;i<a;++i){
    		cin>>par.fi>>par.se;
    		qa.push(par);
    	}
    	for(i=0;i<b;++i){
    		cin>>par.fi>>par.se;
    		qb.push(par);
    	}

    	while(!qa.empty()&&!qb.empty()){
    		if(qa.front().fi<qb.front().fi){
    			res+=qa.front().se*qb.front().se*qa.front().fi;
    			qb.front().fi-=qa.front().fi;
    			qa.pop();
    		}
    		else if(qa.front().fi>qb.front().fi){
    			res+=qa.front().se*qb.front().se*qb.front().fi;
				qa.front().fi-=qb.front().fi;
				qb.pop();
    		}
    		else{
    			res+=qa.front().se*qb.front().se*qa.front().fi;
    			qa.pop();
    			qb.pop();
    		}

    	}

    	cout<<res<<"\n";

    }
    return 0;
}
