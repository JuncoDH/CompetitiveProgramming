#include <math.h>
#include <stdio.h>


using namespace std;


int main(){
	int veces, hh, mm, ss, i, dia, caso, z;
	scanf("%d", &caso);
	for(z=0;z<caso;z++){
		scanf("%d %d:%d:%d", &veces, &hh, &mm, &ss);
		ss*=veces;
		mm*=veces;
		hh*=veces;

		mm+=ss/60;
		ss=ss-floor(ss/60.0)*60;

		hh+=mm/60;
		mm=mm-floor(mm/60.0)*60;

		dia=hh/24;
		hh=hh-floor(hh/24.0)*24;
		
		if(hh<10&&mm<10&&ss<10){printf("%d 0%d:0%d:0%d\n", dia, hh, mm, ss);continue;}
		if(hh<10&&mm<10){printf("%d 0%d:0%d:%d\n", dia, hh, mm, ss);continue;}
		if(hh<10&&ss<10){printf("%d 0%d:%d:0%d\n", dia, hh, mm, ss);continue;}
		if(hh<10){printf("%d 0%d:%d:%d\n", dia, hh, mm, ss);continue;}
		if(mm<10&&ss<10){printf("%d %d:0%d:0%d\n", dia, hh, mm, ss);continue;}
		if(ss<10){printf("%d %d:%d:0%d\n", dia, hh, mm, ss);continue;}
		if(mm<10){printf("%d %d:0%d:%d\n", dia, hh, mm, ss);continue;}
		printf("%d %d:%d:%d\n", dia, hh, mm, ss);




	}
	return 0;
}
