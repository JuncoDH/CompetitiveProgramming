#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <utility>
#include <time.h>
#include <set>
#include <climits>
#include <stack>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int lli;

#define echo(x) cout<<":"<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

stack<int> s;

int main(){
	ios_base::sync_with_stdio(0);
	string cad;
	int casos,z,i,temp,temp2;

	getline(cin,cad);
	casos=stoi(cad);
	for(z=0;z<casos;++z){
		getline(cin,cad);
		i=cad.length()-1;
		s=stack<int>();

		while(i>=0){
			if(cad[i]>='0'&&cad[i]<='9'){
				s.push(cad[i]-'0');
			}
			else if(cad[i]=='+'){
				temp=s.top();
				s.pop();
				temp2=s.top();
				s.pop();
				s.push(temp+temp2);
			}
			else if(cad[i]=='-'){
				temp=s.top();
				s.pop();
				temp2=s.top();
				s.pop();
				s.push(temp-temp2);
			}
			else if(cad[i]=='*'){
				temp=s.top();
				s.pop();
				temp2=s.top();
				s.pop();
				s.push(temp*temp2);
			}
			else{
				temp=s.top();
				s.pop();
				temp2=s.top();
				s.pop();
				s.push(temp/temp2);
			}


			i-=2;
		}

		cout<<s.top()<<"\n";



	}

	return 0;
}
