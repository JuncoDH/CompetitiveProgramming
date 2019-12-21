#include <iostream>

using namespace std;

int main() {
	int caso, z, n, p;
cin>>caso;
for(z=0;z<caso;z++){
	cin>>n>>p;
	if(n>p){
		cout<<"PRINCIPIO\n";
	}
	else{
		cout<<"ROMANCE\n";
	}
}
	return 0;
}