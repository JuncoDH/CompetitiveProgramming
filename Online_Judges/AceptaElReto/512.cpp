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

ll z, casos, a, b;

int main(){
    ios::sync_with_stdio(false);

    cin>>casos;
    for(z=0;z<casos;++z){
    	cin>>a>>b;
    	cout<<((100*a)/(a+b))<<"\n";
    }
    return 0;
}
