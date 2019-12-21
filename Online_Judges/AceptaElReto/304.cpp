#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	int z, casos, d, D;
	cin>>casos;
	for(z=0;z<casos;z++){
		cin>>D>>d;
		if(d==0){cout<<"DIV0"<<endl;continue;}
		if(D>=0||D%d==0){
		cout<<D/d<<" "<<D%d<<endl;
		}
		else if(d>0){
			cout<<(D-d)/d<<" "<<(D%d)+d<<endl;
		}
		else{
			cout<<(D+d)/d<<" "<<(D%d)-d<<endl;
		}


	}

	return 0;
}
