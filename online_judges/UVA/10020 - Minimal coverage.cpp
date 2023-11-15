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


bool myfun(pii a, pii b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}




//for priority_queue, you have to write a < b if you want .top >= all
class myfun2{
public:
    bool ans;
    bool operator() (pii a, pii b) {
        if(a.se != b.se) return a.se < b.se;
        return a.fi > b.fi;
    }
};

int main(){
    ios::sync_with_stdio(false);
    int l, r, m, i, n, cases, z;
    bool flag;
    
    cin >> cases;
    for(z = 0; z < cases; ++z) {
        if(z > 0) cout << "\n";
        
        cin >> m;
        vector<pii> v, ans;
        priority_queue<pii, vector<pii>, myfun2> p;    
        
        while(true) {
            cin >> l >> r;
            if(l == 0 && r == 0) break;
            if(r >= 0 && l <= m) v.pb(mp(l, r));
        }
        sort(v.begin(), v.end(), myfun);
        
        r = 0;
        n = v.size();
        pii actual = {-1, -1};
        flag = false;
        for(i = 0; i < n && r <= m;) {
            while(i < n && v[i].fi <= r) {p.push(v[i]); ++i;}

            if(actual.se <= r) {
                //while(p.empty() == false && p.top().se < r) p.pop();
                //if(p.empty() == true) {flag = true; break;}
                if(p.empty() == true || (p.empty() == false && p.top().se <= r)) {flag = true; break;}
                ans.pb(p.top());
                actual = p.top();
                p.pop();
                if(actual.se >= m) break;
            }
            
            ++r;
        }
        
        if(actual.se >= m) {
            r = m + 1;
        }
        

        while(p.empty() == false && r <= m) {
            if(actual.se <= r) {
                //while(p.empty() == false && p.top().se < r) p.pop();
                //if(p.empty() == true) {flag = true; break;}
                if(p.empty() == true || (p.empty() == false && p.top().se <= r)) {flag = true; break;}
                ans.pb(p.top());
                actual = p.top();
                p.pop();
                if(actual.se >= m) break;
            }
            ++r;
        }
        
        if(actual.se >= m) {
            r = m + 1;
        }
        
        
        
        if(flag ||r <= m) cout << "0\n";
        else{
            n = ans.size();
            cout << n << "\n";
            for(i = 0; i < n; ++i) {
                //if(i > 0) cout << " ";
                cout << ans[i].fi << " " << ans[i].se << "\n";
            }
        }
        

    }


    return 0;
}
