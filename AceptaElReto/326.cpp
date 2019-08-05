#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>
#include <time.h>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define MAX 100005
#define DIM 1005
int parent[MAX],Rank[MAX],n,puntos[MAX][2],tablero[DIM][DIM];


struct DisjoinSets{

	DisjoinSets(){
		int i;
		for(i=0;i<n;++i){
			parent[i]=i;
			Rank[i]=1;
		}
	}

	void Union(int x, int y){
		int xp,yp;
		if(x==-1){x=0;}//cuando lee -1 es la pos 0
		if(y==-1){y=0;}
		xp=findRoot(x);
		yp=findRoot(y);

		if(xp==yp){
			return;
		}
		if(Rank[xp]>Rank[yp]){
			parent[yp]=xp;
		}
		else if(Rank[xp]<Rank[yp]){
			parent[xp]=yp;
		}
		else{
			++Rank[xp];
			parent[yp]=xp;
		}
	}

	int findRoot(int x){
		if(parent[x]!=x){
			parent[x]=findRoot(parent[x]);
		}
		return parent[x];
	}

};

double distancia(int i, int j){
	return sqrt(pow(puntos[i][0]-puntos[j][0],2)+pow(puntos[i][1]-puntos[j][1],2));
}

int main(){
	ios_base::sync_with_stdio(0);
	int i,flag,x,y;
	double k;
	DisjoinSets Ds;

	puntos[0][0]=0;
	puntos[0][1]=0;

	while(cin>>puntos[1][0]>>puntos[1][1]>>k>>n){

		++n;//el punto 0 es el 0,0, el punto 1 es el M,N, el punto 2 es el ultimo que quitan y el n+1 es el primero que quitan

		tablero[0][0]=-1;//sería 0 pero entonces no lo detectaria
		tablero[puntos[1][0]][puntos[1][1]]=1;
		parent[0]=0;
		parent[1]=1;
		Rank[0]=1;
		Rank[1]=1;
		flag=0;

		for(i=n;i>1;--i){
			cin>>puntos[i][0]>>puntos[i][1];
			tablero[puntos[i][0]][puntos[i][1]]=i;
			parent[i]=i;
			Rank[i]=1;
		}
		for(i=1;i<=n;++i){
			//echo(i);
			for(x=puntos[i][0]-k;x<=puntos[i][0]+k;++x){
				if(x<0||x>puntos[1][0]){//se sale del tablero
					continue;
				}
				for(y=puntos[i][1]-k;y<=puntos[i][1]+k;++y){
					if(y<0||y>puntos[1][1]){//se sale del tablero
						continue;
					}

					if(tablero[x][y]&&tablero[x][y]<i&&distancia(i,tablero[x][y])<=k&&(x!=puntos[i][0]||y!=puntos[i][1])){
						//que haya un punto y que no este cortado, que pueda saltar y que no sea el mismo punto
						Ds.Union(i,tablero[x][y]);//los une pues se puede saltar entre ellos
						//cout<<"uno: "<<i<<" "<<tablero[x][y]<<endl;
					}
				}
			}

			if(Ds.findRoot(0)==Ds.findRoot(1)){
				flag=1;
				break;
			}
		}



		if(flag){
			cout<<puntos[i][0]<<" "<<puntos[i][1]<<"\n";
		}
		else{
			cout<<"NUNCA SE PUDO\n";
		}

		for(i=1;i<=n;++i){//borra los puntos del tablero
			tablero[puntos[i][0]][puntos[i][1]]=0;
		}

	}
	return 0;
}
