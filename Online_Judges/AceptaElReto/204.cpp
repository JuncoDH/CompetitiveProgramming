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
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int OK,i;
string s;

int h(){

	++i;

	if(s[i]=='.'||!OK){
		return 0;
	}
	if(s[i]=='*'){
		return 1;
	}
	int temp1, temp2;
	temp1=h();
	temp2=h();
	if(temp1!=temp2&&temp1+1!=temp2&&temp1!=temp2+1){
		OK=0;
		return 0;
	}

	return temp1+temp2;

}

int main(){


	while(cin>>s){
		OK=1;
		i=-1;
		h();

		if(OK){
			cout<<"OK\n";
		}
		else{
			cout<<"KO\n";
		}
	}

	return 0;
}
