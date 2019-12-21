#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int casos, z, n1, n2;
	scanf("%d", &casos);
	for(z=0;z<casos;z++){
		scanf("%d-%d", &n1, &n2);
		if(((n1==n2+1)&&!(n2%2))||((n2==n1+1)&&!(n1%2))){
			printf("SI\n");
		}
		else{
			printf("NO\n");
		}

	}
	return 0;
}