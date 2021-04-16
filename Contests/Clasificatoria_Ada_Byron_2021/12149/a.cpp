#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

int main(){
    ll n;
    while(cin>>n && n){
        ll res = 0;
        for(int i=1;i<=n;++i){
            res+= i*i;
        }
        cout<<res<<"\n";
    }
}