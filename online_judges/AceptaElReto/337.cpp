#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 31543

int main() {

	int casos, z, i, suma, v[6], flag, temp;
	cin>>casos;
	for(z=0;z<casos;z++){
		flag=0;
		for(i=0;i<6;i++){
			cin>>v[i];
		}
		for(i=0;i<6;i++){
			cin>>temp;
			v[i]+=temp;
		}
		suma=v[0];
		for(i=1;i<6;i++){
			if(v[i]!=suma){
				flag=1;
			}
		}
		if(flag){
			cout<<"NO\n";
		}
		else{
			cout<<"SI\n";
		}
	}

	return 0;
}
