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

string s, final, resultado[105];
int i, v, x, l, c, arr[5][20], j, n;
map<int, string> unidades, decenas;



void cont(string num){
	int pos=0;
	for(;pos<num.length();++pos){
		if(num[pos]=='i')++i;
		if(num[pos]=='v')++v;
		if(num[pos]=='x')++x;
		if(num[pos]=='l')++l;
		if(num[pos]=='c')++c;
	}
	resultado[j]=to_string(j)+": "+to_string(i)+" i, "+to_string(v)+" v, "+to_string(x)+" x, "+to_string(l)+" l, "+to_string(c)+" c\n";
}

int main(){
    ios::sync_with_stdio(false);
    unidades[1]="i";
    unidades[2]="ii";
    unidades[3]="iii";
    unidades[4]="iv";
    unidades[5]="v";
    unidades[6]="vi";
    unidades[7]="vii";
    unidades[8]="viii";
    unidades[9]="ix";

    decenas[1]="x";
    decenas[2]="xx";
    decenas[3]="xxx";
    decenas[4]="xl";
    decenas[5]="l";
    decenas[6]="lx";
    decenas[7]="lxx";
    decenas[8]="lxxx";
    decenas[9]="xc";

    i=v=x=l=c=0;

    for(j=1;j<10;++j){
    	s=unidades[j];
    	cont(s);
    }
    for(j=10;j<100;++j){
    	s=decenas[j/10]+unidades[j%10];
    	cont(s);
    }
    j=100;
    s="ccc";
    cont(s);

    while(1){
    	cin>>n;
    	if(n==0)return 0;
    	cout<<resultado[n];
    }

    return 0;
}
