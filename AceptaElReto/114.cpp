#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n, casos, i;
	cin>>casos;
	for(i=0;i<casos;i++){
		cin>>n;
		switch(n){
		case 0:
		case 1:
			cout<<"1";
			break;
		case 2:
			cout<<"2";
			break;
		case 3:
			cout<<"6";
			break;
		case 4:
			cout<<"4";
			break;
		default:
			cout<<"0";
			break;
		}
		cout<<endl;
	}



	return 0;
}