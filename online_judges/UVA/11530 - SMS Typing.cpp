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
int i,z,casos,cont;

int main() {
	ios_base::sync_with_stdio(false);

	getline(cin,s);
	casos=stoi(s);
	for(z=1;z<=casos;++z){
		getline(cin,s);
		cont=0;
		for(i=0;i<s.length();++i){
			switch(s[i]){
			case 'a':case 'd':case 'g':case 'j':case 'm':case 'p':case 't':case 'w':case ' ':
				++cont;break;
			case 'b':case 'e':case 'h':case 'k':case 'n':case 'q':case 'u':case 'x':
				cont+=2;break;
			case 's':case 'z':
				cont+=4;break;
			default:
			cont+=3;



			}


		}
		cout<<"Case #"<<z<<": "<<cont<<"\n";

	}


	return 0;
}
