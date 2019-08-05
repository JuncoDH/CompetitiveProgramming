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

#define MAX 100005
ll A[MAX], B[MAX], i, n;
ll modA[3], modB[3], col[3];

int main(){
    ios::sync_with_stdio(false);

    while(cin>>n){

    	for(i=1;i<=n;++i){
    		cin>>A[i];
    	}
    	for(i=1;i<=n;++i){
    		cin>>B[i];
    	}
    	for(i=0;i<3;++i){
    		modA[i]=col[i]=modB[i]=0;
    	}

    	for(i=1;i<=n;++i){
    		modA[i%3]+=A[i];
    		modB[i%3]+=B[i];
    	}


    	col[0]=modA[0]*modB[0]+modA[1]*modB[2]+modA[2]*modB[1];
    	col[1]=modA[0]*modB[1]+modA[1]*modB[0]+modA[2]*modB[2];
    	col[2]=modA[0]*modB[2]+modA[1]*modB[1]+modA[2]*modB[0];


    	cout<<col[0]<<" "<<col[1]<<" "<<col[2]<<"\n";

    }


    return 0;
}
