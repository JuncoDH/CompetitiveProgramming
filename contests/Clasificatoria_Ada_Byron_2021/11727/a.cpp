#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

int main(){
    ll tt;
    vll v(3);
    cin >> tt;
    for(ll zz = 1; zz <= tt; zz++) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        cout << "Case " << zz << ": " << v[1] << "\n";
    }
    return 0;
}