#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#include <string>
#include <utility>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef long long lli;
typedef pair<int,int> ii;

#define pb push_back
#define mp make_pair
#define echo(x) cout<<": "<<x<<endl;


int main(void) {
	ios::sync_with_stdio(false);
	int a,b,i,n,horas,temp,lim;
	vector<int> bi,bd;
	priority_queue<int> izq,der;

	string s;

		while(cin>>n){
			cin>>a>>b;
			bd.clear();
			bi.clear();
			izq=priority_queue<int>();
			der=priority_queue<int>();
			s="";

			for(i=0;i<a;++i){
				cin>>temp;
				izq.push(temp);
			}

			for(i=0;i<b;++i){
				cin>>temp;
				der.push(temp);
			}

			while(!izq.empty()&&!der.empty()){
				horas=0;
				lim=min(izq.size(),der.size());
				lim=min(lim,n);
				for(i=0;i<lim;++i){
					int iz=izq.top(),de=der.top();
					izq.pop();der.pop();
					if(iz>de){
						horas+=de;
						iz-=de;
						if(iz)bi.pb(iz);
					}
					else{
						horas+=iz;
						de-=iz;
						if(de)bd.pb(de);
					}

				}

				s+=to_string(horas);
				s+=" ";

				for(int el:bi)izq.push(el);
				for(int el:bd)der.push(el);
				bi.clear();
				bd.clear();
			}

			s=s.substr(0,s.length()-1);
			cout<<s<<"\n";

		}

    return 0;
}
