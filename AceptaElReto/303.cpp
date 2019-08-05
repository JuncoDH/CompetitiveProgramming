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

enum {IZQ, DER};
bool AVL;

int f(int minimo,int maximo){
	int node,temp1,temp2;
	cin>>node;
	if(node==-1){
		return 0;
	}
	if((node<=minimo)||(node>=maximo)){
		AVL=false;
	}
	temp1=f(minimo,min(maximo,node))+1;
	temp2=f(max(minimo,node),maximo)+1;

	if(abs(temp1-temp2)>1){
		AVL=false;
	}

	return max(temp1,temp2);

}

int main() {
	ios_base::sync_with_stdio(false);
	int node,temp1,temp2,casos,z;


	cin>>casos;
	for(z=0;z<casos;++z){

		AVL=true;

		cin>>node;
		if(node==-1){
			cout<<"SI\n";
			continue;
		}
		temp1=f(INT_MIN,node);
		temp2=f(node,INT_MAX);
		if(abs(temp1-temp2)>1){
			AVL=false;
		}


		if(AVL){
			cout<<"SI\n";
		}else{
			cout<<"NO\n";

	}
	}

	return 0;
}
