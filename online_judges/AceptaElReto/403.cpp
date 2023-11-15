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
	ios_base::sync_with_stdio(false);
	int casos, z, fut, m;
	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>m>>fut;
		if(m>=fut*90*45&&m<=fut*90*120){
			cout<<"SI\n";
			continue;
		}
		cout<<"NO\n";
	}


	return 0;
}
