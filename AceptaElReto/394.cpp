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
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)


int M,num;

int h(){
	int temp1,temp2;

	cin>>num;

	if(!num){
		return 0;
	}

	if(num==1){
		h();
		return 0;
	}

	temp1=h();
	temp2=h();

	M=max(min(temp1,temp2)+1,M);
	return min(temp1,temp2)+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int casos,z;
	cin>>casos;

	for(z=0;z<casos;++z){
		M=0;

		M=max(h(),M);
		cout<<M<<"\n";


	}
	return 0;
}