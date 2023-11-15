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

ll casos,n,k,p,z;

int main(){
    ios::sync_with_stdio(false);

    cin>>casos;
    for(z=1;z<=casos;++z){

    	cin>>n>>k>>p;

    	cout<<"Case "<<z<<": "<<((k+p+-1)%n)+1<<"\n";




    }



    return 0;
}
