/*WA, missing clear the set<string> v from case to case*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int n, k;
string s;
set<string> v;

void f(int mask, int indice, string t) {
    if(indice == 20) {v.insert(t); return;}
    if(((mask>>indice)&1)==0) {f(mask, indice+1, t); return;}
    string t2 = t;
    t2[indice] = 'A';
    v.insert(t2);
    f(mask, indice+1, t2);
    t2[indice] = 'C';
    v.insert(t2);
    f(mask, indice+1, t2);
    t2[indice] = 'G';
    v.insert(t2);
    f(mask, indice+1, t2);
    t2[indice] = 'T';
    v.insert(t2);
    f(mask, indice+1, t2);
    
}
int c(int num) {
    int ans = 0, i;
    for(i = 0; i < 20; i++) {
        if(((num>>i) & 1)) ans++;
    }
    return ans;
}

int main(void) {
    int mask = 0, i, tt, zz;
    
    cin >> tt;
    for(zz = 0; zz < tt; ++zz) {

        cin >> n >> k;
        if(n == 0) {
            cout << "0\n";
            continue;
        }
        cin >> s;
        for(i = 0; i < (1<<n); i++) {

            if(c(i) != k) continue;
            f(i, 0, s);
        }
        n = v.size();
        cout << n << "\n";
        vector<string> vv;
        for(auto el : v) vv.pb(el);
        for(i = 0; i < n; i++) {
            cout << vv[i] << "\n";
        }
    }
    
    return 0;
}

