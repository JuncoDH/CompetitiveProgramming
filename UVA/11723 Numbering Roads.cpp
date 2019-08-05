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

ll casos,n,r;

int main(){
    ios::sync_with_stdio(false);


    while(1){
    	++casos;
    	cin>>r>>n;
    	if(!n&&!r)return 0;

    	if(27*n<r){
    		cout<<"Case "<<casos<<": impossible\n";
    		continue;
    	}
    	if(r%n==0) cout<<"Case "<<casos<<": "<<r/n-1<<"\n";
    	else cout<<"Case "<<casos<<": "<<r/n<<"\n";




    }



    return 0;
}
