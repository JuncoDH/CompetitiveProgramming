#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

long int longitud(int num){
	if(num==1){
		return 4;
	}
	return 4*(num+longitud(num/2));
}

int main() {
	int n;
	while(cin>>n){
		cout<<longitud(n)<<endl;

	}
	return 0;
}