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

vector<vector<int>> conexion(20005);
int visited[20005],M;

int BFS(int num){
	if(conexion[num].size()<1||visited[num]){
		return 0;
	}
	int total=1,i;
	queue<int> q;
	visited[num]=1;
	q.push(num);
	while(!q.empty()){
		for(i=0;i<conexion[q.front()].size();++i){
			if(visited[conexion[q.front()][i]]){
				continue;
			}
			visited[conexion[q.front()][i]]=1;
			++total;
			q.push(conexion[q.front()][i]);

		}


		q.pop();
	}


	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	int i,n,m,uno,dos,casos,z;

	cin>>casos;
	for(z=0;z<casos;++z){

		cin>>n>>m;
		for(i=0;i<=n;++i){
			conexion[i]=vi();
			visited[i]=0;
		}
		for(i=0;i<m;++i){
			cin>>uno>>dos;
			conexion[uno].pb(dos);
			conexion[dos].pb(uno);
		}
		M=1;

		for(i=0;i<=n;++i){
			M=max(BFS(i),M);
		}
		cout<<M<<"\n";


	}


	return 0;
}
