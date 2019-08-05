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
	int c,p,t,s;
	while(1){
		cin>>c>>p>>t;
		if(!c&&!p&&!t){
			return 0;
		}
		s=1;
		while(t!=0){
			if(p==c){
				s=-1;
			}
			if(p==1){
				s=1;
			}

				p+=s;
				t--;

		}
		cout<<p<<"\n";



	}

	return 0;
}
