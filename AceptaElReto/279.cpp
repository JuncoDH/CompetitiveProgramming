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

int V,E,color[105];//coloreamos con 1 (por defecto) y 2
vector<vi> v(105);

int BFS(){
	int i, j;
	queue<ii> q;//(coloreado,a_colorear)
	for(i=0;i<=V;++i){
		if(v[i].empty()||color[i]){
			continue;
		}
		color[i]=1;

		for(j=0;j<v[i].size();++j){
			q.push(mp(i,v[i][j]));
		}
		while(!q.empty()){

			if(color[q.front().second]==color[q.front().first]){
				return 0;
			}
			if(color[q.front().second]){
				q.pop();
				continue;
			}
			if(color[q.front().first]==1){//no esta coloreado, por lo que lo coloreamos con el otro color
				color[q.front().second]=2;
			}
			else{
				color[q.front().second]=1;
			}
			for(j=0;j<v[q.front().second].size();++j){
				q.push(mp(q.front().second,v[q.front().second][j]));
			}

			q.pop();

		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int i,x,y;

	while(cin>>V){
		cin>>E;

		for(i=0;i<=V;++i){
			color[i]=0;
		}
		v=vector<vi>(105);

		for(i=0;i<E;++i){
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}

		if(BFS()){
			cout<<"SI\n";
		}
		else{
			cout<<"NO\n";
		}

	}

	return 0;
}
