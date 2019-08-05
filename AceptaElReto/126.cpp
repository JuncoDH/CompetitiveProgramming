#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
//long long int n, p;
string n, p;
int sp, sn, i;
	while(1){
		cin>>p>>n;
		if(p[0]=='-'&&n[0]=='-'){break;}

		sp=p.length();
		sn=n.length();
		if(p[0]=='1'&&sp==1){cout<<"YES\n";continue;}
		if(n[0]=='0'&&sn==1){n[0]='1';}
		if(sp<sn){cout<<"YES\n";}
		else if(sp>sn){cout<<"NO\n";}
		else{
			for(i=0;i<sp;i++){
				if(p[i]<n[i]){cout<<"YES\n";break;}
				else if(p[i]>n[i]){cout<<"NO\n";break;}
				if(p[i]==n[i] && i==sp-1){cout<<"YES\n";break;}
				if(i==sp-1){cout<<"NO\n";}
			}

		}


	}


	return 0;
}