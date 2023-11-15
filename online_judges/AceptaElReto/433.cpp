#include <iostream>

using namespace std;

int v[5000];

int main() {
	int i, caso;

	for(i=0;i<5000;i++){
		v[i]=(i*(i-1))/2;
	}

	while(1){
		cin>>caso;
		if(!caso){
			return 0;
		}
		for(i=2;i<5000;i++){
			if(v[i]>=caso){
				cout<<i-1<<endl;
				break;
			}
		}
	}

	return 0;
}