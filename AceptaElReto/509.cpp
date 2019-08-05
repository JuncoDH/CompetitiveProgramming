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

#define MAX 105
typedef pair<lli, lli> pll;
lli grid[MAX][MAX],c,f;
vector<vector<pll>> DP(MAX, vector<pll>(MAX));

//Debug functions
void mostrarDP(){
	int i, j;
	for(i=0;i<f;++i){
		for(j=0;j<c;++j){
			cout<<"("<<DP[i][j].first<<","<<DP[i][j].second<<")";
		}cout<<endl;
	}
}

void mostrargrid(){
	int i, j;
		for(i=0;i<f;++i){
			for(j=0;j<c;++j){
				cout<<grid[i][j]<<" ";
			}cout<<endl;
		}
}

//from (0,0) to (f-1,c-1). It creates the DP backwards
pll DFS(int i, int j){

	if(i==f-1&&j==c-1){
		return mp(0,0);
	}

	if(DP[i][j].first!=0||DP[i][j].second!=0){
		return DP[i][j];
	}

	if(i==f-1){
		pll der=DFS(i,j+1);
		der.second+=grid[i][j];
		der.first+=grid[i][j];
		der.first=min(grid[i][j],der.first);
		return DP[i][j]=der;
	}

	if(j==c-1){
		pll down=DFS(i+1,j);
		down.second+=grid[i][j];
		down.first+=grid[i][j];
		down.first=min(grid[i][j],down.first);
		return DP[i][j]=down;
	}

	pll der=DFS(i,j+1);
	der.second+=grid[i][j];
	der.first+=grid[i][j];
	der.first=min(grid[i][j],der.first);

	pll down=DFS(i+1,j);
	down.second+=grid[i][j];
	down.first+=grid[i][j];
	down.first=min(grid[i][j],down.first);

	return DP[i][j]=max(der,down);
}

int main(void) {
	ios::sync_with_stdio(false);
	int i, j;
	pll final;

	while(cin>>c){
		cin>>f;

		for(i=0;i<f;++i){
			for(j=0;j<c;++j){
				DP[i][j].first=0;//inicializacion
				DP[i][j].second=0;
				cin>>grid[i][j];
			}
		}

		final=DFS(0,0);

		cout<<max((lli)2,(lli)(2-final.first))<<"\n";

	}

    return 0;
}
