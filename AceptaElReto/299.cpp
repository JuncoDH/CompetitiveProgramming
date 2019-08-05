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

vector<vector<ii>> calles(10005);//calle[i][j] es la arista j de la ciudad i, el first es a donde vas y el second el coste
int conectadas[10005],total,n,c,error;

void prim(){
	int flag,i;
	priority_queue<pair<int,int>> p;//-coste,voy ,de donde vengo no importa
	pair<int,int> temp;
	conectadas[1]=1;
	if(calles[1].empty()){
		error=1;
		return;
	}
	for(i=0;i<calles[1].size();++i){
		p.push(mp(-calles[1][i].second,calles[1][i].first));
	}


	while(1){
		flag=0;
		for(i=1;i<=n;++i){
			if(!conectadas[i]){
				flag=1;
				break;
			}
		}
		if(!flag){//si estan todas conectadas
			break;
		}

		while(1){
			if(p.empty()){
				error=1;
				return;
			}
			if(conectadas[p.top().second]){
				p.pop();
				continue;
			}
			break;
		}
		temp=p.top();
		p.pop();
		total+=-temp.first;

		conectadas[temp.second]=1;

		for(i=0;i<calles[temp.second].size();++i){
			p.push(mp(-calles[temp.second][i].second,calles[temp.second][i].first));

		}

	}

}



int main() {
	ios_base::sync_with_stdio(false);
	int i,uno,dos,coste;


	while(cin>>n){
		cin>>c;
		if(n==1){
			cout<<"0\n";
			continue;
		}

		for(i=0;i<=n;++i){
			conectadas[i]=0;
			calles[i]=vector<ii>();
		}

		for(i=0;i<c;++i){
			cin>>uno>>dos>>coste;
			calles[uno].pb(mp(dos,coste));
			calles[dos].pb(mp(uno,coste));
		}

		total=0;
		error=0;
		prim();
		if(error){
			cout<<"Imposible\n";
			continue;
		}
		cout<<total<<"\n";

	}


	return 0;
}
