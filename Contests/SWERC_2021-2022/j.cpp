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

ll w, l;
set<ll> ans;
bool check(ll a) {
    // cout << w << " " << l << endl;
    if(a <= 0) return false;
    if(a == 1) return true;
    if(a == 2) return true;
    if(a > w || a > l) return false;
    ll c = w/a;
    if(c < 1) return false;
    // cout << (l%a) << "asa" << endl;
    if(c*a == w) {
    //cout << a << " " << c << " " << w << " " << l << " " << c*a << " " << ((l-2)%a == 0) <<  endl;
        if((l-2)%a == 0) return true;
    }
    else if(c*a == w-1) {
        if((l-1)%a == 0) return true;
    }
    else if(c*a == w-2) {
        //cout <<"asdf"  << ((l)%a == 0) << " " << (l%a)<< endl;
        if((l)%a == 0) return true;
    }

    return false;
}

void f(ll a) {
    if(check(a)) {
        //cout << "ooo" << endl;
        ans.insert(a);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll tt, mx, i;
    cin >> tt;
    while(tt--) {
        cin >> w >> l;
        ans.clear();
        mx = (long long)sqrt(max(w, l));
        mx += 10;
        for(i = 1; i < mx; i++) {
            f(i);
            f(w/i);
            f((w+1)/i);
            f((w-1)/i);
            f((w+2)/i);
            f((w-2)/i);
            f((w+3)/i);
            f((w-3)/i);
            f((w+4)/i);
            f((w-4)/i);
            f((l)/i);
            f((l+1)/i);
            f((l-1)/i);
            f((l+2)/i);
            f((l-2)/i);
            f((l+3)/i);
            f((l-3)/i);
            f((l+4)/i);
            f((l-4)/i);
        }
        cout << ans.size();
        for(auto el : ans) {
            cout << " " << el;
        }
        cout << "\n";
    }


    return 0;
}