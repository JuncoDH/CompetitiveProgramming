#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ex;

int eq(int pi, int di, int pd, int dd){
	int Pi, Di, Pd, Dd;
	if(pi==0){cin>>Pi>>Di>>Pd>>Dd;pi=eq(Pi, Di, Pd, Dd);}
	if(pd==0){cin>>Pi>>Di>>Pd>>Dd;pd=eq(Pi, Di, Pd, Dd);}
	if(pi*di==pd*dd){return pi+pd;}
	ex=1;
	return 0;
}

int main(){
	int pi, di, pd, dd, res;
	while(1){
		cin>>pi>>di>>pd>>dd;
		if(!pi&&!di&&!pd&&!dd){break;}
		ex=0;
		res=eq(pi, di, pd, dd);
		cout<<(ex?"NO":"SI")<<endl;
	}
	return 0;
}
