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

#define MAX 1005

vector<vector<ii>> ady(MAX);
int visitados[MAX],carga[MAX],n,m,error,total;

void BFS(){
	priority_queue<ii> p;
	ii temp;
	int i;
	if(ady[1].size()<1){
		error=1;
		return;
	}
	for(i=0;i<ady[1].size();++i){
		p.push(mp(-ady[1][i].second,ady[1][i].first));
	}
	visitados[1]=1;
	while(1){
		while(1){
			if(p.empty()){
				error=1;
				return;
			}

			if(visitados[p.top().second]){
				p.pop();
				continue;
			}
			break;
		}
		temp=p.top();
		p.pop();
		visitados[temp.second]=1;
		if(temp.second==n){
			total=-temp.first;
			return;
		}
		for(i=0;i<ady[temp.second].size();++i){
			p.push(mp(temp.first-ady[temp.second][i].second,ady[temp.second][i].first));
		}



	}


}

int main() {
	ios_base::sync_with_stdio(false);
	int i,uno,dos,tiempo;

	while(cin>>n){
		for(i=1;i<=n;++i){
			cin>>carga[i];
			ady[i]=vector<ii>();
			visitados[i]=0;
		}
		cin>>m;
		for(i=0;i<m;++i){
			cin>>uno>>dos>>tiempo;
			ady[uno].pb(mp(dos,tiempo+carga[dos]));
		}
		error=0;
		BFS();

		if(error){
			cout<<"IMPOSIBLE\n";
			continue;
		}
		cout<<total+carga[1]<<"\n";


	}

	return 0;
}
