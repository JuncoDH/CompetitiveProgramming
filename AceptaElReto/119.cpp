#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n, i;
	long long int s;
	while(1){
		cin>>n;
		if(!n){return 0;}
		s=0;
		for(i=sqrt(n)+1;i>0;i--){
			while(i*i<=n){
				s+=i*i+4*i;
				n-=i*i;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
