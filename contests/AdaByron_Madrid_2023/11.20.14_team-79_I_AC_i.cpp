#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll mod1 = 1000000007;
const ll mod2 = 9999;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll i, j, x, y, r1, r2, r, n;
    string s;
    vll pow6(10, 1);
    vll fact6(10, 1);
    for(i = 0; i < 10; i++) {
        pow6[i] = i*i*i;
        pow6[i] = pow6[i]*pow6[i];
        for(j = pow6[i]; j > 1; j--) {
            fact6[i] *= j;
            fact6[i] %= mod1;
        }
    }

    while(cin >> s) {
        if(s == "0") return 0;
        n = s.length();
        for(i = 0; i < n; i += 2) {
            x = s[i]-'0';
            y = s[i+1]-'0';
            if(x == 1) r1 = pow6[y];
            else r1 = fact6[y];

            if(y == 1) r2 = pow6[x];
            else r2 = fact6[x];

            r = (47*r1+r2)%mod2;
            r++;
            // cout << r1 << " " << r2 << endl;
            // temp = to_string(r);
            // while((int)temp.size() < 4) temp
            cout << r;
        }
        cout << "\n";
    }
    
    return 0;
}