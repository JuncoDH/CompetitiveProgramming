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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int n,k,s,e;
vector<int> DP(102*102);
map <int,int> redir;

int BFS(){
	int i;
	queue<ii> q;
	q.push(mp(1,0));
	while(q.front().first!=n*n){
		if(q.front().first>n*n||DP[q.front().first]){
			q.pop();
			continue;
		}
		DP[q.front().first]=1;
		for(i=1;i<=k;++i){
			if(redir.find(q.front().first+i)==redir.end()){
				q.push(mp(q.front().first+i,q.front().second+1));
			}
			else{
				q.push(mp(redir[q.front().first+i],q.front().second+1));
			}
		}
		q.pop();


	}

	return q.front().second;
}

int main() {
	ios_base::sync_with_stdio(false);
	int ini,fin,i;

	while(1){
		cin>>n>>k>>s>>e;
		if(!n&&!k&&!s&&!e){
			return 0;
		}
		redir=map<int,int>();
		DP=vector<int>(102*102);
		s+=e;
		for(i=0;i<s;++i){
			cin>>ini>>fin;
			redir[ini]=fin;
		}

		cout<<BFS()<<"\n";


	}


	return 0;
}
