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
#include <stdio.h>

#define mp(x,y) make_pair(x,y)
#define echo(x) cout<<":"<<x<<endl;

using namespace std;
typedef pair<long,long> ii;
typedef long long lli;

long long int primos[5000];

void rellenarPrimos() {
	int i, p = 1, flag, j;
	primos[0] = 2;
	for (i = 3; true; i += 2) {//10000
		flag = 1;
		for (j = 0; j < p; j++) {
			if (i % primos[j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			primos[p] = i;
			p++;
			//cout<<i<<" "<<INT_MAX<<endl;
			if(primos[p-1]>=sqrt(2147483649)){//INT_MAX
				//cout<<"primo: "<<i<<" pos: "<<p<<"MAX"<<INT_MAX<<endl;
				return;
			}
		}
	}
}


int main(){
    ios::sync_with_stdio(false);

    lli i,k,cont,temp;

    rellenarPrimos();
   primos[4793]=2;//para salir


    //la sol son todos los divisores de k^2 divido entre dos. Se puede sacar por teoria de numeros y sustituyendo x=z+k
    //buscaremos solo los de k
    while(cin>>k){
		cont=1;


		//encuentra los divisores de k^2
		for(i=0;primos[i]<=k;++i){

			if(k==1){
				break;
			}

			if(i==4793){
				cont*=3;
				break;
			}

			if(k%primos[i]==0){
				temp=0;
				while(k%primos[i]==0){
					++temp;
					k/=primos[i];
				}
				cont*=(2*temp+1);
			}
		}


		//la sol es dividido entre 2 por las simetrias x,y
		cout<<(cont+1)/2<<"\n";
    }

    return 0;
}
