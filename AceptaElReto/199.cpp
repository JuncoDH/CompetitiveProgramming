#include <iostream>
#include <algorithm>
#include <math.h>

#include<iomanip>

using namespace std;
/*
int partecien;
int rev(int num){
	//cout<<endl<<num<<" ";
	int x, y=0;
	if(num%10==0){return 0;}
	x=num;
	y=x%10;
	x/=10;
	while(x){
		y=y*10+x%10;
		x/=10;
	}
	num+=y;
	//cout<<num;
	while(num){
		if(num%2==0){return 0;}
		num/=10;
	}
	//cout<<" SI\n";
	partecien++;
	return 1;
}

long long int factorial(int num){
	if(!num){return 1;}
	return num*factorial(num-1);
}

int main(){
	int caso, i, j, cont;
	while(1){
		cin>>caso;
		if(!caso){return 0;}
		cont=0;//for(i=pow(10, caso-1);i<pow(10, caso);i++){if(rev(i)){cont++;}}
		for(i=1;i<10;i++){
			partecien=0;
			for(j=0;j<100;j++){
				if(rev(i*100+j)){cont++;}
			}
			cout<<"El parte100 es: "<<partecien<<endl;

		}

		cout<<endl<<endl<<cont<<endl;
	}



	return 0;
}*/

int main(){
	int caso;
cout.precision(0);
	while(1){
		cin>>caso;
		if(!caso){return 0;}
		if(caso%2==0){cout<<fixed<<20*pow(2,caso/2-1)*pow(3,caso/2-1)*pow(5,caso/2-1)<<endl;continue;}
		if(caso%4==1){cout<<"0\n";continue;}
		cout<<fixed<<20*pow(2,2*(((caso+1)/4)-1))*pow(5,2*(((caso+1)/4)-1))*pow(5,(caso+1)/4)<<endl;

	}

return 0;
}
