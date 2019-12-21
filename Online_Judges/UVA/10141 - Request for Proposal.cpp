#include <bits/stdc++.h>

//#pragma GCC diagnostic ignored "-Wsign-compare"

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main(){
    ios::sync_with_stdio(false);
    
    ll n, p, i, j, k, cases = 1;
    long double price;
    pair<int, long double> m;
    
    string s, name, ans, nline;
    
    while(1){
        cin >> n >> p;
        if(n == 0 && p == 0) return 0;
        if(cases > 1) cout << "\n";
        getline(cin, nline);
        for(i = 0; i < n; ++i) getline(cin, s);
        m = mp(-1, -1.0);
        for(i = 0; i < p; ++i){
            getline(cin, name);
            cin >> price >> k;
            getline(cin, nline);
            for(j = 0; j < k; ++j) getline(cin, s);
            if(m.fi == -1) {m = mp(k, price); ans = name;}
            if(k > m.fi || (k == m.fi && price < m.se) ) {m = mp(k, price); ans = name;}
        }
        
        cout << "RFP #" << cases++ << "\n";
        cout << ans << "\n";

    }



    return 0;
}
