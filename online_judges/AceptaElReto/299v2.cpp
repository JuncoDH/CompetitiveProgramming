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
#include <tuple>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define fi first
#define se second


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX_CALLES 100005
#define MAX_CIUDADES 10005
//(coste, (origen, destino))
vector<pair<int, ii>> aristas(MAX_CALLES);
int n,c,ori,dest,cost, rango[MAX_CIUDADES], parent[MAX_CIUDADES], temp,numaristas;

int findParent(int num){
	if(parent[num]!=num){
		parent[num]=findParent(parent[num]);
	}
	return parent[num];
}

void Union(int n1, int n2){
	n1=findParent(n1);
	n2=findParent(n2);

	if(rango[n1]>rango[n2]){
		parent[n1]=n2;
	}
	else if(rango[n1]<rango[n2]){
		parent[n2]=n1;
	}else{
		parent[n2]=n1;
		++rango[n1];
	}
}

void kruskal(){
	int i;

	cost=numaristas=0;

	for(i=0;i<c;++i){
		ori=aristas[i].se.fi;
		dest=aristas[i].se.se;
		if(findParent(ori)!=findParent(dest)){
			Union(ori, dest);
			cost+=aristas[i].fi;
			++numaristas;
			if(numaristas==n-1)return;//ya ha puesto todas las aristas
		}
	}

	cost=0;//no se puede
}

int main(){
    ios::sync_with_stdio(false);
    int i;

    while(cin>>n){
		cin>>c;

		for(i=0;i<=n;++i){
			parent[i]=i;
			rango[i]=0;
		}

		for(i=0;i<c;++i){
			cin>>ori>>dest>>cost;
			aristas[i]=mp(cost, mp(ori, dest));
		}

		if(n==1){
			cout<<"0\n";
			continue;
		}

		sort(aristas.begin(), aristas.begin()+c);
		kruskal();
		if(cost==0)cout<<"Imposible\n";
		else cout<<cost<<"\n";

    }
    return 0;
}