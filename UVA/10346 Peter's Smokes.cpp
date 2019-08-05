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

ll n, k, cont;

int main(){
    ios::sync_with_stdio(false);

    while(cin>>n){
    	cin>>k;

    	cont=0;

    	cont+=n;

    	while(n>=k){
    		cont+=(n/k);
    		n=n-k*(n/k)+n/k;
    	}

    	cout<<cont<<"\n";
    }


    return 0;
}
