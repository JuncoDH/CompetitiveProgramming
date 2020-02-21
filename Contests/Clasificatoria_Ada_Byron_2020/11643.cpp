#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back


typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;


int main(){
    ll n,a,b;
    while(cin>>n>>a>>b){
        a--;
        b--;
        ll div=2;
        for(int i=1;i<=n;++i){
            if(a/div==b/div){
                cout<<i<<"\n";
                break;
            }
            div*=2;
        }

    }





    return 0;
}