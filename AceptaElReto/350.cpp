#include <stdio.h>
int main() {
	int n,m;
	a:
		scanf("%d %d", &n, &m);
		if(!n&&!m){
			return 0;
		}

		printf("%.1lf\n", (double)(n*m)/2.0);
	goto a;


	return 0;
}