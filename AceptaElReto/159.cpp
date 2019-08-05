#include <stdio.h>
using namespace std;

int main(){
	int h1, min1, h2, min2, digit, cont;
	while(1){
		scanf("%d:%d %d:%d %d", &h1, &min1, &h2, &min2, &digit);
		if(h1==24){return 0;}
		cont=0;
		while(h1<=h2){
			if(h1==h2&&min1>min2){break;}
			if(h1%10==digit||h1/10==digit||min1%10==digit||min1/10==digit){cont++;}
			min1++;
			if(min1==60){min1=0;h1++;}

		}
		printf("%d\n", cont);
	}
	return 0;
}
