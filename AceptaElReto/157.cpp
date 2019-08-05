#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

int main() {
	ios_base::sync_with_stdio(0);
	int  mes[12]={31,28,31,30,31,30,31,31,30,31,30,31},z,casos,m,d,i,cont;

	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>d>>m;

		cont=mes[m-1]-d;
		for(i=m;i<12;++i){
			cont+=mes[i];
		}

		cout<<cont<<"\n";
	}
	return 0;
}
