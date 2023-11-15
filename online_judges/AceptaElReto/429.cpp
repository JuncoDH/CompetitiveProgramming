#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int hangar, nave, i, flag;
	while(cin>>hangar){
		if(hangar==0){break;}
		flag=1;
		vector<int> h(hangar);
		for(i=0;i<hangar;i++){
			cin>>h[i];
		}
		cin>>nave;
		vector<int> n(nave);
		for(i=0;i<nave;i++){
				cin>>n[i];
			}
		for(i=0;i<nave;i++){
			sort(h.begin(),h.end());
			if(h[hangar-1]-n[i]>=0){h[hangar-1]-=n[i];}
			else{flag=0;break;}
		}

		if(flag){cout<<"SI"<<endl;}
		else{cout<<"NO"<<endl;}

	}
	return 0;
}