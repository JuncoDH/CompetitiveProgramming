#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const long long inf = LLONG_MAX/10;

using ld = long double;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const char t[180] = {0};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll i, c = 0, m = 0, h = 0, num, grado;
    set<ll> s;
    s.insert(0);
    for(i=0; i<720; i++){
        c++;
        m++;
        if(c == 12) {
            c = 0;
            h++;
        }
        if(m == 60) m = 0;
        grado = min(abs(h-m), 360-abs(h-m))*6;
        // cout << grado << endl;
        s.insert(grado);
    }
    while(cin >> num) {
        if(s.count(num) == 0) cout << "N\n";
        else cout << "Y\n";
    }
    


    return 0;
}