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

ll n, siguiente,i,cont;
bool flag,sepuede;
stack<ll> s;

int main(){
    ios::sync_with_stdio(false);

    while(1){
    	cin>>n;
    	if(!n)return 0;
    	flag=true;

    	while(flag){
    		s=stack<ll> ();
			i=1;
			sepuede=true;
			for(cont=0;cont<n;++cont){
				cin>>siguiente;
				if(!siguiente){
					flag=false;
					break;
				}

				if(!sepuede)continue;

				while(s.empty()||s.top()!=siguiente){
					if(i>n){
						sepuede=false;
						break;
					}
					s.push(i);
					++i;
				}

				if(!sepuede)continue;
				s.pop();


			}
			if(!flag)break;
    		cout<<(sepuede?"Yes\n":"No\n");
    	}

    	cout<<"\n";
    }



    return 0;
}
