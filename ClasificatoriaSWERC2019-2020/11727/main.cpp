/*AC*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(void) {
    ll n, zz;
    vector<ll> v(3);
    cin>>n;
    for(zz = 0; zz < n; zz++) {
        cin >> v[0] >> v [1] >> v[2];
        sort(v.begin(), v.end());
        cout << "Case " << zz+1 << ": " << v[1] << "\n";
    }

    return 0;
}
/*
3
1000 2000 3000
3000 2500 1500
1500 1200 1800
        */