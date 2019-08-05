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
#include <set>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int teclas[8*12];

int tecla(string s) {
	if(s=="Dob"){
		return -1;
	}
	if(s=="Si#"){
		return 12;
	}
	if (s == "Do") {
		return 0;
	}
	if (s == "Do#" || s == "Reb") {
		return 1;
	}
	if (s == "Re") {
		return 2;
	}
	if (s == "Re#" || s == "Mib") {
		return 3;
	}
	if (s == "Fab" || s == "Mi") {
		return 4;
	}
	if (s == "Mi#" || s == "Fa") {
		return 5;
	}
	if (s == "Fa#" || s == "Solb") {
		return 6;
	}
	if (s == "Sol") {
		return 7;
	}
	if (s == "Sol#" || s == "Lab") {
		return 8;
	}
	if (s == "La") {
		return 9;
	}
	if (s == "La#" || s == "Sib") {
		return 10;
	}
	return 11;
}

int casilla(string cad){
	int num=stoi(cad.substr(cad.length()-1,1));

	return (num-1)*12+tecla(cad.substr(0,cad.length()-1));
}

int main() {
	ios_base::sync_with_stdio(false);
	int i,n,j;
	string s;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		for(i=0;i<8*12;++i){
			teclas[i]=0;
		}
		for(i=0;i<n;++i){
			cin>>s;
			++teclas[casilla(s)];
		}
		for(j=7*12;j>=0;--j){
			if(teclas[j]){
				break;
			}
		}

		for(i=0;i<=j;++i){
			if(!teclas[i]){
				continue;
			}
			cout<<teclas[i];
			break;
		}
		for(++i;i<=j;++i){
			cout<<" "<<teclas[i];
		}



		cout<<"\n";


	}

	return 0;
}
