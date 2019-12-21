/*AC*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(void) {
    ll n, i, sum;
    while(true) {
        cin >> n;
        if(n == 0) return 0;
        sum = 0;
        for(i = 1; i <= n; i++) {
            sum += i*i;
        }
        cout << sum << "\n";
    }
    
    return 0;
}

