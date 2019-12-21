#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <utility>
#include <cstring>
#include <limits.h>

using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define echo(x) cout<<":"<<(x)<<endl;
#define first fi
#define second se


typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

string cad;
int i;
stack<char> s;
bool sepuede;

int main(){
    ios::sync_with_stdio(false);

    while(getline(cin,cad)){

    	if(cad==""){
    		cout<<"YES\n";
    		continue;
    	}

    	s=stack<char>();
    	sepuede=true;

    	//2 = (* y 3  = *), preprocessing
    	for(i=0;i<cad.length();++i){
    		if(cad[i]=='2')cad[i]='4';
    		if(cad[i]=='3')cad[i]='4';
    	}
    	for(i=0;i<cad.length()-1;++i){
    	    if(cad[i]=='(' && cad[i+1]=='*')
    	    	cad=cad.substr(0,i)+"2" + cad.substr(i+2,cad.length()-i-2);
    	}
    	for(i=1;i<cad.length();++i){
    		if(cad[i]=='*' && cad[i+1]==')')
    			cad=cad.substr(0,i)+"3" + cad.substr(i+2,cad.length()-i-2);
    	}



    	for(i=0;i<cad.length();++i){
    		if(cad[i]=='2'||cad[i]=='('||cad[i]=='['||cad[i]=='{'||cad[i]=='<'){
    			s.push(cad[i]);
    			continue;
    		}
    		if(cad[i]=='3'){
    			if(s.empty()||s.top()!='2'){
    				sepuede=false;
    				break;
    			}
    			s.pop();
    		}
    		if(cad[i]==')'){
				if(s.empty()||s.top()!='('){
					sepuede=false;
					break;
				}
				s.pop();
			}
    		if(cad[i]=='}'){
				if(s.empty()||s.top()!='{'){
					sepuede=false;
					break;
				}
				s.pop();
			}
    		if(cad[i]==']'){
				if(s.empty()||s.top()!='['){
					sepuede=false;
					break;
				}
				s.pop();
			}
    		if(cad[i]=='>'){
				if(s.empty()||s.top()!='<'){
					sepuede=false;
					break;
				}
				s.pop();
			}
    	}

    	if(!s.empty()||!sepuede)cout<<"NO "<<i+1<<"\n";
    	else cout<<"YES\n";

    }


    return 0;
}
