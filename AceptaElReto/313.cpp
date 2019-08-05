#include <iostream>


using namespace std;

int main(){
	int c, a, b;
	cin>>c;
	c++;
	while(--c){
		cin>>a>>b;
		cout<<((a+b>=0)? "SI":"NO")<<endl;
	}

	return 0;
}
