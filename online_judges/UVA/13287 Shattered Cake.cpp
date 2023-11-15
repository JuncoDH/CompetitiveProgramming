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

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll w, n, i, x, y, cuadrados;

int main(){
    ios::sync_with_stdio(false);

    while(cin>>w){
    	cin>>n;
    	cuadrados=0;
    	for(i=0;i<n;++i){
    		cin>>x>>y;
    		cuadrados+=(x*y);
    	}
    	cout<<cuadrados/w<<"\n";
    }


    return 0;
}
