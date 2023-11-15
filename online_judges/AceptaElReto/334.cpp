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

enum {GALO = 1,ROMANO,GODO,GRIEGO,NORMANDO,BRETON,HISPANO,INDIO,PICTO,VARIAS};
string  s,temp, h[11] = { "PLUS ULTRA", "GALO", "ROMANO", "GODO", "GRIEGO",
		"NORMANDO", "BRETON", "HISPANO", "INDIO", "PICTO", "MULATO" };

int main() {

	int z, casos, flag;







	getline(cin,s);
	casos=stoi(s);
	for (z = 0; z < casos; ++z) {
		getline(cin, s);
		//cout<<s<<" "<<s.length();

		flag = 0;
		if (s[s.length() - 1] == 'A') {
			flag = INDIO;
		}
		if (s.length() < 2) {
			cout << h[flag] << "\n";
			continue;
		}
		temp = s.substr(s.length() - 2, 2);

		if (temp == "IX") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = GALO;
		}
		if (temp == "US"||temp=="UM") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = ROMANO;
		}
		if (temp == "IC") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = GODO;
		}
		if (temp == "AS") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = GRIEGO;
		}
		if (temp == "AF") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = NORMANDO;
		}
		if (temp == "IS"||temp=="OS"||temp=="AX") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = BRETON;
		}
		if (temp == "EZ") {
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = HISPANO;
		}

		if(s.length()<3){
			cout<<h[flag]<<"\n";
			continue;
		}
		if(s.substr(0,3)=="MAC"){
			if (flag != 0) {
				cout << h[VARIAS] << "\n";
				continue;
			}
			flag = PICTO;
		}
		cout<<h[flag]<<"\n";

	}
	return 0;
}