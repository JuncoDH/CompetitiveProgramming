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
 

vll fact(21);

void fill_fact(){ll i; fact[0] = 1; for(i = 1; i < 21; ++i) fact[i] = fact[i - 1] * i;}


ll v_to_rank(vll per){
    ll i, n = per.size(), _rank = 1, comb;
    map<ll, ll> m; //(number, nº of times rep)
    for(ll el : per) m[el]++;

    for(i = 0; i < n; ++i){
        comb = fact[n - i - 1];
        for(auto rest : m)
            comb /= fact[rest.se];
        
        for(auto smaller : m) {
            if(smaller.fi >= per[i]) break;
            _rank += comb * smaller.se;
        }
        
        if(m[per[i]] > 1)m[per[i]]--;
        else m.erase(per[i]);
    }
    return _rank;
}

vll rank_to_v(ll _rank, vll alpha) {
    ll n = alpha.size(), i, comb, sum;
    pll last;
    vll ans;
    sort(alpha.begin(), alpha.end());
    map<ll, ll> m;
    
    for(auto el : alpha) m[el]++;
    
    for(i = 0; i < n; ++i) {
        comb = fact[n - i - 1];
        for(auto ele : m)
            comb /= fact[ele.se];
        last = mp(-1ll, -1ll);    
        sum = 0;
        
        for(auto ele : m) {
            if(last == mp(-1ll, -1ll)) {last = ele; continue;}
            if(sum + comb * last.se >= _rank) break;
            sum += comb * last.se;
            last = ele;
        } 

        _rank -= sum;
        ans.pb(last.fi);
        if(m[last.fi] > 1) m[last.fi]--;
        else m.erase(last.fi);
    }

    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);

    fill_fact();

    ll i, t, num;
    string s;
    vll ans, per;

    cin >> t;
    while(t--) {
        cin >> s;
        cin >> num;
        ++num;
        per = vll();
        for(i = 0; i < (int)s.length(); ++i) per.pb((int)s[i]);
        ans = rank_to_v(num, per);
        for(i = 0; i < (int)ans.size(); ++i) cout << (char)ans[i];
        cout << "\n";
    }


    return 0;
}