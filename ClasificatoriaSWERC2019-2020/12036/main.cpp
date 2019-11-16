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
    ll tt, zz, i, n, j, num;
    bool flag;
    cin >> tt;
    for(zz = 0; zz < tt; ++zz) {
        cin >> n;
        flag = true;
        vector<ll> h(200, 0);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> num;
                h[num]++;
                if(h[num] > n) flag = false;
            }
        }
        cout << "Case " << zz+1 << ": ";
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }
    
    
    return 0;
}
/*
3
4
2 1 1 3
3 1 2 6
2 6 10 3
9 8 7 6
3
1 1 2
1 1 1
2 2 2
3
1 2 3
2 3 1
3 1 2
*/