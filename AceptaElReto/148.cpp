#include <iostream>
#include <math.h>
#include <string>
#include <cmath>

using namespace std;

#define MAX 1005
#define show(x) cout<<":"<<x<<endl

int main() {
	int mm, ss;
	while(1){
	scanf("%d:%d",&mm,&ss);
	if(!mm&!ss){
		return 0;
	}
	printf("%d\n", (24*60)-(mm*60+ss));
	}
	return 0;
}
