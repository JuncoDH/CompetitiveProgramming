#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
	int n;
	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		cout<<(((n*(n+1))/2)*3)<<endl;



	}
	return 0;
}

