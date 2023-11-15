#include <bits/stdc++.h>
 
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


#define x first
#define y second
vector<pii> v(20);
vector<long double> dp;
ll n;

long double dist(int i, int j){
    ll dx = v[i].x - v[j].x;
    ll dy = v[i].y - v[j].y;
    return sqrt(dx * dx + dy * dy);
}


void bfs(){
    int i, j, newmask, mask = 0;

    queue<int> q;
    set<int> visited;
    q.push(0);
    
    while(q.empty() == false){
        mask = q.front();
        q.pop();
        if(visited.find(mask) != visited.end()) continue;
        visited.insert(mask);
        
        for(i = 0; i < n; ++i){
            if((mask >> i) & 1) continue;
            for(j = i + 1; j < n; ++j){
                if((mask >> j) & 1) continue;
                newmask = mask | (1ll << i) | (1ll << j);
                dp[newmask] = min(dp[newmask], dp[mask] + dist(i, j));
                q.push(newmask);
            }
		break; //necessary, it's compulsory fill the first gap
        }
    
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    ll i, Case = 1;
    string s;
    
    cout.precision(2);
    cout << fixed;

    while(true){
    
        cin >> n;
        if(n == 0) return 0;
        
        n *= 2;
        dp.assign((1ll << n), INT_MAX);
        for(i = 0; i < n; ++i){
            cin >> s >> v[i].x >> v[i].y;
        }
        
        dp[0] = 0;
        
        bfs();
        
        cout << "Case " << Case++ << ": " << round(dp[(1ll<<n) - 1] * 100) / 100 << "\n";
    }


    return 0;
}

