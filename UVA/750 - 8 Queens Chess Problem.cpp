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

#define y1 yasdfafd
vector<bool> d1, d2, row, col;
int x1, y1;
vector<int> ans;
int n_sol;

bool valid(int i, int j) {
    if(row[i] || col[j] || d1[i + j] || d2[i - j + 7]) return false;
    return true;
}

void Set(int x1, int y1) {
    row[x1] = true;
    col[y1] = true;
    d1[x1 + y1] = true;
    d2[x1 - y1 + 7] = true;
}

void unSet(int x1, int y1) {
    row[x1] = false;
    col[y1] = false;
    d1[x1 + y1] = false;
    d2[x1 - y1 + 7] = false;
}

void backtrack(int y) {
    int i;
    
    if(y == 9) {
        if(n_sol < 10) cout << " ";
        cout << n_sol++ << "      ";
        for(i = 0; i < 8; ++i) {
            if(i > 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
        return;
    }
    if(y == y1) {
        ans.pb(x1);
        backtrack(y + 1);
        ans.pop_back();
        return;
    }
    
    for(i = 1; i <= 8; ++i) {
        if(valid(i, y)) {
            ans.pb(i);
            Set(i, y);
            backtrack(y + 1);
            unSet(i, y);
            ans.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int test;
    
    cin >> test;
    
        
    while(test--) {
        d1.assign(17, false);
        d2.assign(15, false);
        row.assign(9, false);
        col.assign(9, false);
        
        cin >> x1 >> y1;
        //x1 = y1 = 1;
        Set(x1, y1);
        n_sol = 1;
        
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        
        backtrack(1);
    
        if(test) cout << "\n";
    }
    
    return 0;
}