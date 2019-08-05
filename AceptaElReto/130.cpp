#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

#define MAX 1000


int main() {
	int n, x1, y1, x2, y2;
	while (1) {
		cin >> n;
		if(!n){
			return 0;
		}
		cin >> x1 >> y1 >> x2 >> y2;
		if((x1+y1)%2!=(x2+y2)%2){
			cout<<"IMPOSIBLE\n";
			continue;
		}
		if(x1==x2 && y1==y2){
			cout<<"0\n";
		}
		else if(x1-y1==x2-y2||x1+y1==x2+y2){
			cout<<"1\n";
		}
		else{
			cout<<"2\n";
		}


	}
	return 0;
}
