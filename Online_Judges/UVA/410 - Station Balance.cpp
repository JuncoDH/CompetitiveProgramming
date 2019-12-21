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
    ll n, m, i, j, Min, mi, nSet = 1;
    long double imbalance, avg, cavg;
    
    cout.precision(5);
    

    while(cin >> n) {
        cin >> m;

        vi c(n, 0), countc(n, 0), v(m);
        vector<vi> vc(n);
        avg = 0;
        for(i = 0; i < m; ++i) {
            cin >> v[i];
            avg += v[i];
        }
        avg /= n;
        imbalance = 0;
        sort(all(v), greater<int>());
        for(i = 0; i < m; ++i) {
            Min = c[0];
            mi = 0;
            for(j = 1; j < n; ++j) {
                if(countc[j] < 2 && c[j] < Min) {
                    Min = c[j];
                    mi = j;
                }
            }
            c[mi] += v[i];
            countc[mi]++;
            vc[mi].pb(v[i]);
        }

        cout << "Set #" << nSet++ << "\n";
        for(i = 0; i < n; ++i) {
            cout << " " << i << ":";
            cavg = 0;
            for(j = vc[i].size() - 1; j >= 0; --j) {
                cout << " " << vc[i][j];
                cavg += vc[i][j];
            }

            imbalance += abs(cavg - avg);
            cout << "\n";
        }
        
        
        
        cout << "IMBALANCE = " << fixed << imbalance << "\n\n";
    }

    return 0;
}