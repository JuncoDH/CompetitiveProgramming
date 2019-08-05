#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#include <string>
#include <utility>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef long long lli;
typedef pair<int,int> ii;

#define pb push_back
#define mp make_pair
#define echo(x) cout<<": "<<x<<endl;

#define MAX 20005
vector<vector<ii>> ady(MAX); //ady[a] = (b1,t1)...(bi,ti)
bool visited[MAX],posible;
lli n,c,a,b,t,k,ini,dest,mincalles;

int BFS(){
	lli i;
	queue<pair<int, int>> q;//(pos,num calles)
	memset(visited,false,n+1);

	for(i=0;i<ady[ini].size();++i){
		q.push(mp(ady[ini][i].first,1));
	}
	visited[ini]=true;

	while(!q.empty()){

		if(q.front().first==dest){
			return q.front().second;
		}

		if(visited[q.front().first]){
			q.pop();
			continue;
		}

		visited[q.front().first]=true;

		for(i=0;i<ady[q.front().first].size();++i){
			q.push(mp(ady[q.front().first][i].first,q.front().second+1));
		}

		q.pop();

	}

	return 0;
}

int BFSextendido(){
	lli i;
	priority_queue<pair<ii, int>> q;//((-dist,-num calle),pos)
	memset(visited,false,n+1);

	for(i=0;i<ady[ini].size();++i){
		q.push(mp(mp(-ady[ini][i].second,-1),ady[ini][i].first));
	}
	visited[ini]=true;

	while(!q.empty()){

		if(q.top().second==dest){
			//guardar el numero de calles
			if(-q.top().first.second==mincalles){
				posible=true;
			}

			return -q.top().first.first;
		}

		if(visited[q.top().second]){
			q.pop();
			continue;
		}

		visited[q.top().second]=true;

		for(i=0;i<ady[q.top().second].size();++i){
			q.push(mp(mp(q.top().first.first-ady[q.top().second][i].second,q.top().first.second-1),ady[q.top().second][i].first));
		}

		q.pop();

	}

	return 0;
}

int main(void) {
	lli i;

	while(cin>>n){
		cin>>c;

		ady=vector<vector<ii>>(MAX);

		for(i=0;i<c;++i){
			cin>>a>>b>>t;
			ady[a].pb(mp(b,t));
			ady[b].pb(mp(a,t));
		}
		cin>>k;
		for(i=0;i<k;++i){
			cin>>ini>>dest;
			mincalles=BFS();
			if(!mincalles){
				cout<<"SIN CAMINO\n";
				continue;
			}
			posible=false;
			cout<<BFSextendido();
			if(posible){
				cout<<" SI\n";
			}
			else{
				cout<<" NO\n";
			}
		}

		cout<<"----\n";

	}
    return 0;
}
