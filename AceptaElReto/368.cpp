#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, h, c;
	while(1){
		cin>>h>>c;
		t=0;
		if(!h&&!c){
			return 0;
		}
		if(h%c){
			t=1;
		}
		cout<<(h/c)*10+t*10<<endl;

	}
	return 0;
}
