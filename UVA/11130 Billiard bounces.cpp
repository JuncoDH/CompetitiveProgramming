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

#define PI (2*asin(1))
double a, b, v, A, s, xf, yf;


int main(){
    ios::sync_with_stdio(false);

    while(1){
		cin>>a>>b>>v>>A>>s;
		if(!a&&!b&&!v&&!A&&!s)return 0;

		//conversion a radianes
		A=A*2*PI/360;


		//calcula las coordenadas finales
		xf=cos(A)*v*s/2 + a/2;
		yf=sin(A)*v*s/2 + b/2;

		cout<<(int)(xf/a)<<" "<<(int)(yf/b)<<"\n";


    }
    return 0;
}
