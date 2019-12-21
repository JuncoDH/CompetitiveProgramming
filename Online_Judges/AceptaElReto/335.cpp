#include <iostream>
#include <math.h>


using namespace std;

int main(){
	int c;
	long long x, a;
	cin>>c;
	c++;
	while(--c){
		cin>>a;
		x=(a*a*a+3*a*a+2*a)/6;
		if(x<pow(10, 18)){
		cout<<x<<endl;
		}
	}

	return 0;
}
