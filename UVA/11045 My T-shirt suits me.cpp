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
#include <stdio.h>

#define mp(x,y) make_pair(x,y)
#define echo(x) cout<<":"<<x<<endl;

using namespace std;
typedef pair<long,long> ii;
typedef long long ll;


//Edmonds-Karp Algorithm

//s source, t sink, M number of people
int s,t,M,N;
#define Mmax 40
int parent[Mmax];
bool visited[Mmax];

int graph[Mmax][Mmax];

void mostrar(){
	int i,j;
	for(i=0;i<M;++i){
		for(j=0;j<M;++j){
			cout<<graph[i][j]<<" ";
		}cout<<endl;
	}
}

bool BFS(){
	int u,v;
	memset(visited,false,M);

	queue<int> q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty()){
		u=q.front();
		q.pop();

		for(v=0;v<M;++v){
			if(!visited[v]&&graph[u][v]>0){
				q.push(v);
				parent[v]=u;
				visited[v]=true;
			}

		}
	}


	return (visited[t]==true);
}

int fordFulkerson(){
	int maxflow=0,u,v;

	while(BFS()){
		int path_flow=INT_MAX;

		for(v=t;v!=s;v=parent[v]){
			u=parent[v];
			path_flow=min(path_flow,graph[u][v]);
		}

		for(v=t;v!=s;v=parent[v]){
			u=parent[v];
			graph[u][v]-=path_flow;
			graph[v][u]+=path_flow;
		}

		maxflow+=path_flow;
	}

	return maxflow;
}

int main(){
    ios::sync_with_stdio(false);
    int i,j,z,cases;
    string s;


    	t=1;//the sink

    	cin>>cases;
    	for(z=0;z<cases;++z){


			cin>>N>>M;

			M+=8;//s,t,XXL,XL,L,M,S,XS

			for(i=0;i<M;++i){
				for(j=0;j<M;++j){
					graph[i][j]=0;
				}
			}

			for(j=2;j<8;++j){
				graph[0][j]=N/6;
			}

			for(i=8;i<M;++i){
				graph[i][1]=1;
			}

			for(i=8;i<M;++i){
				for(j=0;j<2;++j){
					cin>>s;
					if(s=="XXL"){
						graph[2][i]=1;
					}
					else if(s=="XL"){
						graph[3][i]=1;
					}
					else if(s=="L"){
						graph[4][i]=1;
					}
					else if(s=="M"){
						graph[5][i]=1;
					}
					else if(s=="S"){
						graph[6][i]=1;
					}
					else{
						graph[7][i]=1;
					}
				}



			}

			//mostrar();

			//cout << "The maximum possible flow is " << fordFulkerson();
			if(fordFulkerson()!=M-8){
				cout<<"NO\n";
			}else{
				cout<<"YES\n";
			}


    	}

    return 0;
}
