#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	double sep, vmax, sec;
	while(1){
	cin>>sep>>vmax>>sec;
	if(!sep&&!vmax&&!sec){break;}
	if(sep<=0||vmax<=0||sec<=0){cout<<"ERROR\n";continue;}
	if(vmax>=(sep/1000)/(sec/(60*60))){cout<<"OK\n";continue;}
	if(1.2*vmax>(sep/1000)/(sec/(60*60))){cout<<"MULTA\n";continue;}
	else{cout<<"PUNTOS\n";}
	}
	return 0;
}