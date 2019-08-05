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

#define mp(x,y) make_pair(x,y)
#define echo(x,s) cout<<"\n"<<s<<":"<<(x)<<endl;
#define echo_tablero(width,height,arr) for(int i=0;i<height;i++){for(j=0;j<width;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n,arr) for(int i=0;i<n;++i){cout<<arr[i]<<" ";}cout<<"\n";

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

vector<int> v(1000005);

int main(){
    ios::sync_with_stdio(false);
    long long int z, casos, i,n,m,cont;

    cin>>casos;
    for(z=0;z<casos;++z){
    	cin>>n>>m;

    	cont=0;

    	for(i=0;i<m;++i){
    		cin>>v[i];
    	}

    	sort(v.begin(),v.begin()+m);

    	for(i=1;i<m;++i){
    		if(v[i]==v[i-1]){//si hay dos seguidos que son iguales avanza dos posiciones y sigue buscando, pues el peso de cada paquete no importa
    			++cont;
    			if(cont==n){
    				break;
    			}
    			++i;
    		}
    	}

    	cout<<cont<<"\n";



    }

    return 0;
}
