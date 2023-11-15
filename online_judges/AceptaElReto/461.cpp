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
#include <time.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)



int main() {
	ios_base::sync_with_stdio(false);
	int i, n,necesito,bajas,temp,total,vivos;
	priority_queue<pair<int,ii>> p;
	pair<int,ii>temporal;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		for(i=0;i<n;++i){
			cin>>necesito>>bajas>>temp;
			bajas+=temp;
			p.push(mp(necesito-bajas,mp(necesito,bajas)));//Los ordena por la base que vaya a dejar mas vivos necesarios
		}
		total=0;
		vivos=0;
		while(!p.empty()){
			temporal=p.top();
			p.pop();
			if(vivos<max(temporal.second.first,temporal.second.second)){
				total+=max(temporal.second.first,temporal.second.second)-vivos;
				vivos=max(temporal.second.first,temporal.second.second);
			}
			vivos-=temporal.second.second;

		}
		cout<<total<<"\n";

	}
	return 0;
}

