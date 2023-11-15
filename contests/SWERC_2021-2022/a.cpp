#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vl data(11,-1);
        int set=0;
        for(int i=0;i<n;++i){
            ll a,b;
            cin>>a>>b; 
            if(data[b]==-1){
                data[b]=a;
                set++;
            }
            else{
                data[b]=max(a,data[b]);
            }
        }
        if(set!=10){
            cout<<"MOREPROBLEMS\n";
        }
        else{
            ll sum = 0;
            for(int i=1;i<=10;++i){
                sum+=data[i];
            }
            cout<<sum<<"\n";
        }
    }
    return 0;
}