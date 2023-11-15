#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, b1, b2, n, m, i, k;
    string s, t, s2, t2;

    cin >> tt;
    while(tt--) {
        cin >> s >> t;
        b1 = b2 = 0;
        n = s.size();
        m = t.size();
        for(i = 0; i < n; i++) b1++;
        for(i = 0; i < m; i++) b2++;
        if(b1%2 != b2%2) {
            cout << "NO\n";
            continue;
        }
        s2 = "";
        for(i = 0; i < n; i++) {
            if(s[i] == 'A') s2.pb('A');
            if(s[i] == 'C') s2.pb('C');
            k = (int)s2.size();
            // cout << "mik" << k << " :" << s2[k-2] << "." << s2[k-1] << endl;
            if(k >= 2 && s2[k-2] == s2[k-1]) {
                // cout << "entroo" << endl;
                s2.pop_back();
                s2.pop_back();
            }
        }
        t2 = "";
        for(i = 0; i < m; i++) {
            if(t[i] == 'A') t2.pb('A');
            if(t[i] == 'C') t2.pb('C');
            k = (int)t2.size();
            if(k >= 2 && t2[k-2] == t2[k-1]) {
                t2.pop_back();
                t2.pop_back();
            }
        }
        // cout << s2 << ".." << t2 << endl;
        if(s2 == t2) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
} 