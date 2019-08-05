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


ll i,n,k,p1,p2,num,respuesta;

void divisores(){
	for(i=2;i<=num;++i){
		if(num%i==0){
			p1=num/i;
			p2=i;

			k=(p2-p1-1)/2;
			n=p1+k;

			//cout<<p1<<" "<<p2<<" n: "<<n<<" k: "<<k<<endl;
			if(k>=0&&n-k==num/i&&n+k+1==i){
				respuesta=n-k;
				return;
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(false);


    while(cin>>num){
		num*=2;
		respuesta=1;
		divisores();
		cout<<respuesta<<"\n";

    }
    return 0;
}
