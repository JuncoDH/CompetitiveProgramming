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
    int num, ans, mask = 0b11111111, add, cpy;

    while(cin >> num) {
        cpy = num;
        ans = 0;
        
        add = mask & num;
        ans |= add << 24;
        num >>= 8;
        
        add = mask & num;
        ans |= add << 16;
        num >>= 8;
        
        add = mask & num;
        ans |= add << 8;
        num >>= 8;
        
        add = mask & num;
        ans |= add;
        
        cout << cpy << " converts to " << ans << "\n";
    }

    return 0;
}

