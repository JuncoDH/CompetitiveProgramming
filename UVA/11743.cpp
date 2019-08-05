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
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int i,z,casos,bloque,suma1,suma2,num;


int main() {
	ios_base::sync_with_stdio(false);

	cin>>casos;
	for(z=0;z<casos;++z){
		suma1=0;
		suma2=0;
		for(i=0;i<4;++i){
			cin>>bloque;//cuarto
			suma1+=(bloque%10);
			bloque/=10;

			num=bloque%10;//tercero
			num*=2;
			if(num>9){
				num=(num%10)+1;
			}
			suma2+=num;
			bloque/=10;

			suma1+=(bloque%10);//segundo
			bloque/=10;

			num=bloque%10;//primero
			num*=2;
			if(num>9){
				num=(num%10)+1;
			}
			suma2+=num;

		}
		if((suma1+suma2)%10==0){
			cout<<"Valid\n";
		}
		else{
			cout<<"Invalid\n";
		}

	}


	return 0;
}
