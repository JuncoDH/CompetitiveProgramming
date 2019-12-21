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



const int MAX = 1005;
vi LIS, W(MAX), L(MAX);

int main(){
    ios::sync_with_stdio(false);
    int n, i, j, LIS_len, Back;
    
    while(true) {
        cin >> n;
        if(n == 0) return 0;
       
        for(i = 0; i < n; ++i) {
           cin >> W[i] >> L[i];
        }

        LIS.clear();
        LIS.pb(L[0]);
        LIS_len = 1;

        //Modification of O(n logk) LIS from end to begin. It runs in O(n k), we update every element for a possible longest LIS
        for(i = 1; i < n; ++i) {
            Back = LIS.back();
            for(j = LIS_len - 1; j >= 1; --j) {
                if(LIS[j - 1] < W[i]) continue;
                LIS[j] = max(min(LIS[j - 1] - W[i], L[i]), LIS[j]);
            }
            
            if(Back >= W[i]) {
                LIS.pb(min(Back - W[i], L[i]));
                LIS_len++;
            }
            LIS[0] = max(LIS[0], L[i]);
            
        }
        
        cout << LIS.size() << "\n";
    }
    
    return 0;
}