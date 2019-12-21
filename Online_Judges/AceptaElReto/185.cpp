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

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x);cout<<endl;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)



int main() {
	ios_base::sync_with_stdio(false);
	string s;
	int i,j,n;
	set<string> aceptado,rechazado;
	vector<string> final;

	while(1){
		cin>>n;
		if(!n){
			return 0;
		}
		aceptado=set<string>();
		rechazado=set<string>();
		final=vector<string>();
		for(i=0;i<n;++i){
			cin>>s;
			if(s=="SI:"){
				while(1){
					cin>>s;
					if(s=="FIN"){
						break;
					}
					aceptado.insert(s);
				}
			}else{
				while(1){
					cin>>s;
					if(s=="FIN"){
						break;
					}
					rechazado.insert(s);
				}

			}

		}
		for(auto it=rechazado.begin();it!=rechazado.end();++it){
			if(aceptado.find(*it)==aceptado.end()){
				final.pb(*it);
			}
		}
		sort(final.begin(),final.end());
		if(final.size()>0){
			cout<<final[0];
		}
		for(j=1;j<final.size();++j){
			cout<<" "<<final[j];
		}
		cout<<"\n";



	}


	return 0;
}
