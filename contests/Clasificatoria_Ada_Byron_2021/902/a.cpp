#include <bits/stdc++.h>
#define se second
#define fi first
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

int main(){
    int n;
    string s;

    while(cin>>n>>s){
        unordered_map<string,int> ma;
        for(int i=0;i<(int)s.length()-(n-1);++i){
            ma[s.substr(i,n)]++;
        }
        int i=0;
        string sa;
        for(auto a:ma){
            if(a.se>i){
                sa=a.fi;
                i=a.se;
            }
        }
        cout<<sa<<"\n";
    }
    return 0;
}