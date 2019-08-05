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

ll num, numero, sum;

int main(){
    ios::sync_with_stdio(false);

    while(1){
    	cin>>num;
    	if(!num)break;
    	numero=1;
    	sum=num;
    	while(1){
    		cin>>num;
    		if(!num)break;
    		sum+=num;
    		++numero;

    	}
    	if(sum%numero!=0){
    		cout<<"IMPOSIBLE\n";
    	}else{
    		cout<<"REPARTO JUSTO\n";
    	}
    }
    return 0;
}
