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

stack<char> st;
string s;
ll casos, z, i, flag;

int main(){
    ios::sync_with_stdio(false);


    getline(cin,s);
    casos=stoi(s);
    for(z=0;z<casos;++z){
    	//cin>>s;
    	getline(cin,s);
    	if(s==""){
    		cout<<"Yes\n";
    		continue;
    	}
    	flag=1;
    	st=stack<char>();
    	for(i=0;i<s.length();++i){
    		if(s[i]=='('||s[i]=='['){
    			st.push(s[i]);
    			continue;
    		}
    		if(s[i]==')'){
    			if(st.empty()||st.top()!='('){
    				flag=0;
    				break;
    			}
    			st.pop();
    		}
    		else{
    			if(st.empty()||st.top()!='['){
    				flag=0;
    				break;
    			}
    			st.pop();
    		}
    	}
    	if(flag&&st.empty())cout<<"Yes\n";
    	else cout<<"No\n";
    }


    return 0;
}
