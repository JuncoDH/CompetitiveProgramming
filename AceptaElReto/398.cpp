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
typedef pair<int,int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)


int posb[105][2], botones,temp1,temp2;//En posb estan todos los botones, considerando posb[0] como el inicio 1,1 y posb[botones+1] la salida
map<pair<int,ii>,int> DP; //guardamos los resultados de las llamadas

int distancia(int b1, int b2){
	return abs(posb[b1][0]-posb[b2][0])+abs(posb[b1][1]-posb[b2][1]);
}//distancia entre dos puntos

int lanzar(int r1, int r2, int retardo){
	//cout<<r1<<" "<<r2<<" "<<retardo<<endl;
	/*
	 * Resumen:
	 * la funcion compara entre el minimo de lanzar un raton o el otro
	 * los considera indistinguibles, r1 es el raton avanzado y r2 el otro
	 * el retardo es el tiempo de ventaja que puede moverse libremente el r2
	 */

	if(r1==botones+1){
		//consideramos que la salida es un ultimo boton a alcanzar
		return max(retardo,distancia(r2,botones+1));
	}

	if(DP.find(mp(r1,mp(r2,retardo)))!=DP.end()){//ya se llamo anteriormente
		return DP[mp(r1,mp(r2,retardo))];
	}
	temp1=max(distancia(r2,r1+1)-retardo,0);
	if(temp1<=retardo){
		return DP[mp(r1,mp(r2,retardo))]=min(lanzar(r1+1,r2,retardo+distancia(r1,r1+1)),retardo+lanzar(r1+1,r1,temp1));
	}
	return DP[mp(r1,mp(r2,retardo))]=min(lanzar(r1+1,r2,retardo+distancia(r1,r1+1)),lanzar(r1+1,r1,temp1)+retardo);
//			lo guarda DP   						lanza al r1                          lanza al r2

}

int main() {
	ios_base::sync_with_stdio(false);
	int i;
	posb[0][0]=1;
	posb[0][1]=1;

	while(cin>>temp2){
	cin>>temp1>>botones;

	DP = map<pair<int,ii>,int> (); //Reseteamos el map
	posb[botones+1][0]=temp1;
	posb[botones+1][1]=temp2;

	if(!botones){ //Si no hay botones es inmediato
		cout<<distancia(0,1)+1<<"\n";
		continue;
	}

	for(i=1;i<=botones;++i){
		cin>>posb[i][1]>>posb[i][0];
	}

	cout<<lanzar(1,0,distancia(0,1))+1<<"\n";

	}
	return 0;
}
