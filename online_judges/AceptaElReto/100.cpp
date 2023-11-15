#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){

	int casos, num;
	vector<int> c(4);
	int i, n1, n2, cont;
	scanf("%d", &casos);
	while(casos--){
		if(casos<0){break;}
		scanf("%d", &num);
		if(num==0||num==1111||num==2222||num==3333||num==4444||num==5555||num==6666||num==7777||num==8888||num==9999){
			printf("8\n");
		}
		else{
			cont=0;
			while(num!=6174){
				if(num>9999||num<1){return 0;}
			for(i=0;i<4;i++){
				c[i]=num%10;
				num/=10;
			}
			sort(c.begin(), c.end());
			n1=c[3]+10*c[2]+100*c[1]+1000*c[0];
			n2=c[0]+10*c[1]+100*c[2]+1000*c[3];
			num=n2-n1;cont++;


			}

		printf("%d\n", cont);
		}
	}

	return 0;
}
