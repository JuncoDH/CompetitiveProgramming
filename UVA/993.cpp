#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

string s;
long int casos, z,n,divisor;

int main() {
	ios_base::sync_with_stdio(false);

	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>n;
		s="";
		if(n==1){
			cout<<"1\n";
			continue;
		}
		if(!n){
			cout<<"0\n";
			continue;
		}
		divisor=9;
		while(n!=1&&divisor!=1){
			while(n%divisor==0){
				n/=divisor;
				s=to_string(divisor)+s;
			}
			--divisor;

		}
		if(n==1){
			cout<<s<<"\n";
		}
		else{
			cout<<"-1\n";
		}



	}


	return 0;
}
