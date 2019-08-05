#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<x<<endl
#define echo_tablero(n) for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
#define echo_array(n) for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;

#define MAX 1000000

int main() {
	int z,casos,num,cont,dif,adif, temp;

	cin>>casos;
	for(z=0;z<casos;z++){
		cin>>temp;
		cin>>num;
		adif=(num-temp+MAX)%MAX;
		cont=0;
		while(1){
			temp=num;
			cin>>num;
			if(num==-1){
				cout<<cont<<" "<<(temp+adif)%MAX<<endl;
				break;
			}
			dif=(num-temp+MAX)%MAX;
			if(dif!=adif){
				adif=dif;
				cont++;
			}




		}
	}
	return 0;
}

