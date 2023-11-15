#include <iostream>

using namespace std;

int main() {
	long long int casos,z,n;

	cin>>casos;
	for(z=0;z<casos;z++){
		cin>>n;
		if(n%3==1){cout<<"NO\n";continue;}
		cout<<"SI\n";
	}

	return 0;
}