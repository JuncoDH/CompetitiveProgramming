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

ll n;

bool valid(ll mask) {
    ll n1 = mask;
    ll n2 = n * mask, i;
    set<int> s;
    for(i = 0; i < 5; ++i) {
        s.insert(n1 % 10);
        s.insert(n2 % 10);
        n1 /= 10;
        n2 /= 10;
    }
    if(n2 != 0 || s.size() != 10) return false;

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    ll mask;
    bool flag;
    bool first = true;

    while(true) {
        scanf("%lld", &n);
        if(n == 0) return 0;
        
        if(first == false) printf("\n");
        
        flag = false;
        for(mask = 1; mask < 50000; ++mask) {
            if(!valid(mask)) continue;
            flag = true;
            printf("%05lld / %05lld = %lld\n", n * mask, mask, n);
        }
        
        if(flag == false) printf("There are no solutions for %lld.\n", n);
        
       first = false;
    
    }

    return 0;
}
