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

int T[10];

void triangle(){
	int i;
	for(i=0;i<10;++i){
		T[i]=(i*(i+1))/2;
	}
}

//Slow formula
int f(int num){
	if(num%10!=0)return num%10;
	return f(num/10);
}

//Fast formula
ll formula(ll num){
	if(num==0)return 0;
	return T[num%10]+45*(num/10)+formula(num/10);
}


void checkFormula(){
	ll i,j,cont;

	    triangle();

	    for(j=0;j<300;++j){
	    	cont=0;
			for(i=1;i<=j;++i){
				cont+=f(i);
			}
			cout<<j<<": "<<cont<<" .. "<<formula(j)<<endl;
	    }
}


int main(){
    ios::sync_with_stdio(false);
    ll p, q;

    triangle();


    while(1){
    	cin>>p>>q;
    	if(p<0&&q<0){
    		return 0;
    	}
    	if(p==0)cout<<formula(q)<<"\n";
    	else cout<<formula(q)-formula(p-1)<<"\n";

    }

    return 0;
}
