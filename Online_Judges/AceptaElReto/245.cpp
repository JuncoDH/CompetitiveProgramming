#include <iostream>

using namespace std;

int main(){
	int ex1, ex2;
	long long int n, z, p1, p2;
	while(1){
		cin>>n;
		if(!n){break;}
		cin>>p1;
		ex1=0;ex2=0;
		for(z=1;z<n;z++){
			cin>>p2;
			if(p1>=p2){ex1=1;}
			if(p1<=p2){ex2=1;}
			p1=p2;
		}
		if(ex1&&ex2){cout<<"DESCONOCIDOS"<<endl;}
		else{cout<<"DALTON"<<endl;}

	}

	return 0;
}
