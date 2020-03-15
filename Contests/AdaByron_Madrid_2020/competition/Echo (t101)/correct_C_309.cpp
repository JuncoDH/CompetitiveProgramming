
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main(int argc, char** argv) {
    string s;
    ll n, k, i;
    map<string, ll> m;
    
    getline(cin, s);
    n = stoll(s);
    
    vector<string> v;
    for(i = 0; i < n; i++) {
        getline(cin, s);
        v.pb(s);
        m[s]++;
    }
    getline(cin, s);
    k = stoll(s);
    
    set<ll> st;
    for(auto el : v) {
        st.insert(-m[el]);
    }
    i = 0;

    for(auto el : st) {
        i++;
        if(i == k ) {k = -el; break;}
    }
    /*cout << k << endl;
    ll cont = 0;
    for(auto el : v) {
        cout << el << " " << m[el] << endl;
        if(m[el] == k) ++cont;
    }

    cout << cont << "\n";*/
    vector<string> ans;
    set<string> sans;
    for(auto el : v) {
        if(m[el] == k) {
            if(sans.count(el)) continue;
            ans.pb(el);
            sans.insert(el);
        }
    }
    cout << ans.size() << "\n";
    for(auto el : ans) {
        cout << el << "\n";
    }

    
    return 0;
}

