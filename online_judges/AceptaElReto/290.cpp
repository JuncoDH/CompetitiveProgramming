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

string s;
int i;

int h(){
	++i;
	if(s[i]=='.'){
		return 0;
	}
	return max(h(),h())+1;

}

int main() {
	ios_base::sync_with_stdio(false);
	int casos,z;

	cin>>casos;
	for(z=casos;z;--z){
		cin>>s;
		i=-1;
		cout<<h()<<"\n";
	}

	return 0;
}
