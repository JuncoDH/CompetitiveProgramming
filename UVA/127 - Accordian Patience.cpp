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

vector<vector<string>> v;

bool match(string a, string b){
    if(a[0] == b[0] || a[1] == b[1]) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    string s;
    int i, j;
    
    while(true) {
    
         v = vector<vector<string>>();
        for(i = 0; i < 52; ++i) {
            cin >> s;
            if(s == "#") return 0;
            
            if(v.size() >= 3 &&  match(v[v.size() - 3].back(), s)) v[v.size() - 3].pb(s);
            else if(v.size() >= 1 &&  match(v[v.size() - 1].back(), s)) v[v.size() - 1].pb(s);
            else {vector<string> vnew = {s}; v.pb(vnew);}
            
            for(j = 0; j < (int)v.size(); ++j) {
                if(j >=3 && match(v[j - 3].back(), v[j].back())) {
                    v[j - 3].pb(v[j].back());
                    v[j].pop_back();
                    if(v[j].size() == false) v.erase(v.begin() + j);
                    j = 0;
                    continue;
                }
                if(j >= 1 && match(v[j - 1].back(), v[j].back())) {
                    v[j - 1].pb(v[j].back());
                    v[j].pop_back();
                    if(v[j].size() == false) v.erase(v.begin() + j);
                    j = 0;
                    continue;
                }
            }
            
            /*echo("fin1");
            for(i = 0; i < (int)v.size(); ++i) {
                if(i > 0) cout << " ";
                cout << v[i].size();
            }*/
            
        }
        
        if(v.size() == 1) cout << "1 pile remaining: ";
        else cout << v.size() << " piles remaining: ";
        
        for(i = 0; i < (int)v.size(); ++i) {
            if(i > 0) cout << " ";
            cout << v[i].size();
        }
        
        cout << "\n";
    }

    return 0;
}