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
#include <fstream>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define fi first
#define se second


typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll n, anteriores, i, media;
string res;

int main(){
    ios::sync_with_stdio(false);

    while(cin>>n){
    	res="";
    	anteriores=0;
    	for(i=1;i<=n;++i){
    		cin>>media;
    		res+=to_string(media*i-anteriores);
    		res+=" ";
    		anteriores+=(media*i-anteriores);
    	}

    	cout<<res.substr(0, res.length()-1)<<"\n";


    }

    return 0;
}
