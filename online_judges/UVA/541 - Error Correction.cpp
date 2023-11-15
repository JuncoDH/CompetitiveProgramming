#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;



int main(){
	int n, i, j, arr[100][100], Sfila[100], Scol[100], fila_cambio, ifila, col_cambio, icol;

	while(cin>>n){
		if(!n){break;}
		for(i=0;i<100;i++){
			Sfila[i]=0;
			Scol[i]=0;
			for(j=0;j<100;j++){
				arr[i][j]=0;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>arr[i][j];
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				Sfila[i]+=arr[i][j];
				Scol[i]+=arr[j][i];
			}
		}
		fila_cambio=0;ifila=0;col_cambio=0;icol=0;
		for(i=0;i<n;i++){
			if(Sfila[i]%2){fila_cambio++;ifila=i;}
			if(Scol[i]%2){col_cambio++;icol=i;}
		}
		if(!fila_cambio&&!col_cambio){
			cout<<"OK\n";
			continue;
		}
		if(fila_cambio>1||col_cambio>1){
			cout<<"Corrupt\n";
			continue;
		}
		else{
			cout<<"Change bit ("<<ifila+1<<","<<icol+1<<")\n";
		}

	}

	return 0;
}
