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
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MOD 31543
ll n;

/*ELEVA EN LOG2(n)*/
ll elevar(ll x){
	ll temp;
	if(x==0)return 1;
	temp=elevar(x/2);
	temp%=MOD;
	if(x%2==0)return (temp*temp)%MOD;
	else return (n*(temp*temp)%MOD)%MOD;

}

int main(){
    ios::sync_with_stdio(false);
    ll x;

    while(1){
    	cin>>n>>x;

    	if(!n&&!x)return 0;

    	if(n==0){
    		cout<<"0\n";
    		continue;
    	}

    	cout<<elevar(x)<<"\n";

    }

    return 0;
}
