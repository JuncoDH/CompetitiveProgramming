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
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl

long long int n, num, den,flag,denominador, numerador,i,j,gcd;
long long int nums[10010], dens[10010],inuevo;



int main() {
	//ios_base::sync_with_stdio(false);


	while(1){
		scanf("%lld", &n);
		if(!n){
			return 0;
		}
		inuevo=0;
		for(i=0;i<n;++i){
			scanf("%lld/%lld", &num, &den);
			flag=0;
			for(j=0;j<inuevo;++j){
				if(dens[j]==den){
					nums[j]+=num;
					flag=1;
					break;
				}
			}
			if(!flag){
				nums[inuevo]=num;
				dens[inuevo]=den;
				++inuevo;
			}



		}
		denominador=1;
		for(i=0;i<inuevo;++i){
			gcd=__gcd(denominador,dens[i]);
			if(gcd==1){
				denominador*=dens[i];
			}
			else{
				denominador*=(dens[i]/gcd);
			}

		}
		numerador=0;
		for(i=0;i<inuevo;++i){
			numerador+=(nums[i])*(denominador/dens[i]);
		}

		printf("%lld\n", denominador-numerador);


	}



	return 0;
}