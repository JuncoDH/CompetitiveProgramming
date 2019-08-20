#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define LSB(x) ((x) & (-(x)))


typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vi dp(1ll << 12, -1);

int Count(int num) {
    int ans = 0;
    while(num) {ans += num & 1; num >>=1;}
    return ans;
}

bool isSet(int num, int id) {
    return (num >> id) & 1;
}

int f(int mask) {
    if(dp[mask] != -1) return dp[mask];
    
    int i, ans = Count(mask), num;
    for(i = 1; i < 11; ++i) {
        if(isSet(mask, i) == false) continue;
        if(isSet(mask, i + 1) == true && isSet(mask, i - 1) == false) {
            num = mask | (1ll << (i - 1));
            num ^= 1ll << i;
            num ^= 1ll << (i + 1);
            ans = min(ans, f(num));
        }
        if(isSet(mask, i + 1) == false && isSet(mask, i - 1) == true) {
            num = mask | (1ll << (i + 1));
            num ^= 1ll << i;
            num ^= 1ll << (i - 1);
            ans = min(ans, f(num));
        }
    }

    return dp[mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    string s = "-o----ooo---";
    int i, mask, t = 1;
    dp[0] = 0;
    
    cin >> t;
    while(t--) {
        cin >> s;
        mask = 0;
        for(i = 0; i < 12; ++i) {
            if(s[11 - i] == 'o') mask |= 1ll << i;
        }

        cout << f(mask) << "\n";
    
    }
    
    return 0;
}


