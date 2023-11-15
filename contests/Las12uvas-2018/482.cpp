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
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;


int main() {
	ios_base::sync_with_stdio(false);
	long long int n, g;
	char c;


	while (1) {
		cin>>c;
		if(c=='.'){
			return 0;
		}
		n=0;
		g=0;
		if(c=='N'){
			n++;
		}
		else if(c=='G'){
			g++;
		}
		while(1){
			cin>>c;
			if(c=='.'){
				break;
			}
			if(c=='N'){
				n++;
			}
			else if(c=='G'){
				g++;
			}

		}
		if(n%2==0&&g%2==0){
			cout<<"EMPAREJADOS\n";
			continue;
		}
		if(n%2!=0&&g%2==0){
			cout<<"NEGRO SOLITARIO\n";
			continue;
		}
		if(n%2==0&&g%2!=0){
			cout<<"GRIS SOLITARIO\n";
			continue;
		}
		if(n%2!=0&&g%2!=0){
			cout<<"PAREJA MIXTA\n";
			continue;
		}


	}

	return 0;
}