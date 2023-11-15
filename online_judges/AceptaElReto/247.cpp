#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, men, ex, i, x;

	while(1){
		cin>>n;
		ex=1;
		if(!n){return 0;}
		cin>>men;
		for(i=0;i<n-1;i++){
			cin>>x;
			if(men>=x){ex=0;}
			men=x;
		}
		if(ex){cout<<"SI"<<endl;}
		else{cout<<"NO"<<endl;}
	}

	return 0;
}