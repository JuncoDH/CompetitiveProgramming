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
	long long int casos, z,i,duermo,n,guardado,prev,temp,total;

	cin>>casos;
	for(z=0;z<casos;++z){
		cin>>n>>duermo;
		guardado=0;
		total=0;
		cin>>prev;
		for(i=1;i<n;++i){
			cin>>temp;
			if(temp-guardado>duermo){
				total++;
				guardado=prev;
			}
			prev=temp;
		}

		cout<<total+1<<"\n";
	}

	return 0;
}