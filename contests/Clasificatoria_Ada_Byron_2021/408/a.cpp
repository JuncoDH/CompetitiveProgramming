#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

ll gcdEx(ll a, ll b, ll *x1, ll *y1){
    if(a==0){
        *x1=0;
        *y1=1;
        return b;
    }
    ll x0,y0,g;
    g= gcdEx(b%a, a, &x0, &y0);
    *x1 = y0-(b/a)*x0;
    *y1=x0;
    return g;
}

int main(){
    ll n,m;
    while(cin>>n>>m){
        ll a1,a2;
        ll g = gcdEx(n,m, &a1, &a2);
        if(g==1){
            printf("%10lld%10lld    %s\n\n",n,m,"Good Choice");
        }
        else{
            printf("%10lld%10lld    %s\n\n",n,m,"Bad Choice");
        }
    }
    return 0;
}