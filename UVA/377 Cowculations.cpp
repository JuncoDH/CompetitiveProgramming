#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s1, s2, res;
char op[3];
int num1, num2, resultado, diez[9];

void convert(){
	int i;
	for(i=0;i<5;++i){
		if(s1[i]=='V')s1[i]='0';
		if(s1[i]=='U')s1[i]='1';
		if(s1[i]=='C')s1[i]='2';
		if(s1[i]=='D')s1[i]='3';
		if(s2[i]=='V')s2[i]='0';
		if(s2[i]=='U')s2[i]='1';
		if(s2[i]=='C')s2[i]='2';
		if(s2[i]=='D')s2[i]='3';
	}
	for(i=0;i<8;++i){
		if(res[i]=='V')res[i]='0';
		if(res[i]=='U')res[i]='1';
		if(res[i]=='C')res[i]='2';
		if(res[i]=='D')res[i]='3';
	}

}

int main(){
    ios::sync_with_stdio(false);
    int i,j, casos, z;

    //potencias de 10
    num1=diez[0]=1;
    for(i=1;i<10;++i){
    	num1*=10;
    	diez[i]=num1;
    }
    cout<<"COWCULATIONS OUTPUT\n";
    cin>>casos;
    for(z=0;z<casos;++z){

		cin>>s1>>s2>>op[0]>>op[1]>>op[2]>>res;
		convert();
		num1=stoi(s1);
		num2=stoi(s2);
		resultado=stoi(res);

		for(i=0;i<3;++i){
			switch(op[i]){
			//suma modulo 4
				case 'A':
					num2+=num1;
					for(j=0;j<8;++j){
						if((num2/diez[j])%10>=4){
							num2-=4*diez[j];
							num2+=diez[j+1];
						}
					}
					num2%=diez[8];

					break;
				//shifters
				case 'L':
					num2*=10;
					num2%=diez[8];
					break;
				case 'R':
					num2/=10;
					break;

			}
		}
		//echo(num2);
		//echo(resultado);
		if(num2==resultado)cout<<"YES\n";
		else cout<<"NO\n";

    }

    cout<<"END OF OUTPUT\n";

    return 0;
}
