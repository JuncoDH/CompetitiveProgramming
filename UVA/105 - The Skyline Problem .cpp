#include <bits/stdc++.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

priority_queue<pair<int, pii> > p;
vector<pair<int, pii> > v;


int main(){
    ios::sync_with_stdio(false);
    
    int l, h, r, i, pos, last, v_size;
    string ans = "";
    
    //CARACTER DE ESCAPE
    while(cin>>l){ //&& l!=-1){
        cin>>h>>r;
        v.pb(mp(h, mp(l, r)));
    }


    last = -1;

    v_size = v.size();
    
    for(i = 0, pos = 1; pos < 10001; ++pos){
        while(i < v_size && v[i].se.fi == pos) {p.push(v[i]); ++i;}
        
        while(p.empty() == false && pos >= p.top().se.se) p.pop();
        
        if(p.empty() == true) p.push(mp(0, mp(0, 0)));
        
        if(last != p.top().fi) {ans += to_string(pos) + " " + to_string(p.top().fi) + " "; last = p.top().fi; }
    }

    cout << ans.substr(0, ans.length()-1) << endl;

    return 0;
}