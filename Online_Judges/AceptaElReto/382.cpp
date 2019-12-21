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
#define fi first
#define se second


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define MAX 2005
int ltunel, n, i, x, rango,pos,flag, cont,casos, z;
//(pos, -1 si empieza intervalo y 1 si acaba(en la posicion pos++))
vector<ii> v(MAX);

int main(){
    ios::sync_with_stdio(false);

    cin>>casos;
    for(z=0;z<casos;++z){
		cin>>ltunel>>n;
		pos=0;
		for(i=0;i<n;++i){
			cin>>x>>rango;
			v[pos]=mp(max(x-rango, 0),-1);
			++pos;
			if(x+rango>=ltunel){
				continue;//no pone la negativa pues cubre mas que el final
			}
			v[pos]=mp(x+rango+1,1);
			++pos;
		}

		sort(v.begin(), v.begin()+pos);

		flag=1;cont=0;
		//si no cubre el x=0
		if(v[0].fi!=0){
			cout<<"NO\n";
			continue;
		}
		for(i=0;i<pos;++i){
			cont-=v[i].se;
			if(!cont){
				flag=0;
				break;
			}
		}

		if(flag)cout<<"SI\n";
		else cout<<"NO\n";

    }
    return 0;
}
