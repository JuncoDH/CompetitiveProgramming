#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll; 

int main(){
    ll n, i;
    while(cin >> n) {
        vll v(n), a;
        for(i = 0; i < n; i++) {
            cin >> v[i];
            if(i > 0) {
                a.pb(abs(v[i] - v[i-1]));
            }
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for(i = 0; i < n-1; i++) {
            if(a[i] != i+1) {ok = false; break;}
        }
        if(ok) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0;
}