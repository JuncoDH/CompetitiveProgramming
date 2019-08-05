#include <bits/stdc++.h>

using namespace std;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
    ios::sync_with_stdio(false);
    int casos, z, n, M, i, money[15];
    pii num;
    
    cin >> casos;
    
    for(z = 0; z < casos; ++z){
        cin >> n >> M;
        
        for(i = 0; i < n; ++i) cin >> money[i];
        
        queue<pii> q;
        set<int> DP;
        
        for(i = 0; i < n; ++i) q.push(mp(money[i], 1));
        
        while(q.empty() == false){
            num = q.front();
            q.pop();
            
            if(num.se == M + 1) break;
            
            if(DP.find(num.fi) != DP.end()) continue;
            DP.insert(num.fi);
            
            for(i = 0; i < n; ++i) q.push(mp(num.fi + money[i], num.se + 1));

        }
        
        cout << DP.size() << "\n";

               
    }
   
   
   
    return 0;
}