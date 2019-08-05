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

int arr[51][51],x,y;
// N E S O, 0 1 2 3

void mostrarT(){
	int i,j;
	for(i=0;i<x;++i){
		cout<<arr[i][0];
			for(j=1;j<y;++j){
				cout<<" "<<arr[i][j];
			}
			cout<<"\n";
		}
}

void simulacion(int i, int j, int dir,int pasos){
	//cout<<"sim:"<<i<<" "<<j<<" "<<dir<<" "<<pasos<<endl;
	int maxpasos=1,cont;
	if(!pasos){
		return;
	}

	++arr[i][j];


	while(1){
	if(dir==0){// N E
		for(cont=0;cont<maxpasos;++cont){
			--i;
			--pasos;
			if(i<0||pasos<0){
				return;
			}
			++arr[i][j];
		}
		for(cont=0;cont<maxpasos;++cont){
			++j;
			--pasos;
			if(j>=y||pasos<0){
				return;
			}
			++arr[i][j];
		}
		++maxpasos;
		dir=2;
	}
		if (dir == 1) {// E S
			for (cont = 0; cont < maxpasos; ++cont) {
				++j;
				--pasos;
				if (j>=y || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			for (cont = 0; cont < maxpasos; ++cont) {
				++i;
				--pasos;
				if (i >= x || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			++maxpasos;
			dir = 3;
		}
		if (dir == 2) {// S O
			for (cont = 0; cont < maxpasos; ++cont) {
				++i;
				--pasos;
				if (i >=x || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			for (cont = 0; cont < maxpasos; ++cont) {
				--j;
				--pasos;
				if (j <0 || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			++maxpasos;
			dir = 0;
		}
		if (dir == 3) {//O N
			for (cont = 0; cont < maxpasos; ++cont) {
				--j;
				--pasos;
				if (j < 0 || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			for (cont = 0; cont < maxpasos; ++cont) {
				--i;
				--pasos;
				if (i<0 || pasos < 0) {
					return;
				}
				++arr[i][j];
			}
			++maxpasos;
			dir = 1;
		}


	}



}

int main() {
	ios_base::sync_with_stdio(false);
	int numpoll,k,i,j,pasos,casos,z;
	char dir;

	cin>>casos;
	for(z=0;z<casos;++z){
	cin>>x>>y>>numpoll;

	for(i=0;i<x;++i){
		for(j=0;j<y;++j){
			arr[i][j]=0;
		}
	}

	for(k=0;k<numpoll;++k){
		cin>>i>>j>>dir>>pasos;
		--i;//para no empezar en 1,1
		--j;
		if(dir=='N'){
			simulacion(i,j,0,pasos);
		}
		else if(dir=='E'){
			simulacion(i,j,1,pasos);
		}
		else if(dir=='S'){
			simulacion(i,j,2,pasos);
		}
		else{
			simulacion(i,j,3,pasos);
		}
	}

	mostrarT();
	cout<<"---\n";
	}


	return 0;
}
