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
#include <climits>
#include <stack>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)


int main(){
	ios_base::sync_with_stdio(0);
	lli n;
	while(cin>>n){
		cout<<floor(log2(n))+1<<"\n";
	}
	return 0;
}
