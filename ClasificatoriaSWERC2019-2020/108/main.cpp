/*WA missing endl at the end*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll arr[110][110];
ll psum[110][110];

int main(void) {
    int n;
    cin>>n;
    for (ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            cin>>arr[i][j];
        }
    }
    for (ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            psum[i][j+1]=psum[i][j]+arr[i][j];
        }
    }

    ll ma=INT_MIN;
    for(ll y1=1;y1<n+1;++y1){
        for(ll y2=0;y2<y1;++y2){
            ll csum=0;
            for(int i=0;i<n;++i){
                csum+=psum[i][y1]-psum[i][y2];
                ma=max(ma,csum);
                if(csum<0)csum=0;
            }
        }
    }
    cout<<ma<<"\n";
    return 0;
}
/*
 4
 0 -2 -7 0 9 2 -6 2
 -4 1 -4 1 -1
  8 0 -2
 
 
 */
