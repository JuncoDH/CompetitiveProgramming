#include <bits/stdc++.h>
using namespace std;
using ll = int;
using vll = vector<ll>;

#define mp make_pair
#define pb push_back

const ll MAX = 104;
// const ll inf = LLONG_MAX/10;
const int inf = INT_MAX/10;
ll inix, iniy, finx, finy;
ll f(ll x) { // 0 -> 50, -1 -> 49, -50 -> 0, 50 -> 100
    return x+51;
}
int obs[MAX][MAX];
ll dp[MAX][MAX][5];
ll best_time;
void g(ll x, ll y, ll dir, ll tiempo) {
    // ll ret, ans = inf;
    if(x < 0 || x >= MAX || y < 0 || y >= MAX) return;
    if(obs[x][y] == 1) return;
    if(tiempo >= best_time) return;
    if(dp[x][y][dir] != -1 && dp[x][y][dir] <= tiempo) return;
    // cout << x << " " << y << " " << dir << " " << tiempo << " " << dp[x][y][dir] << " " << best_time << endl;
    dp[x][y][dir] = tiempo;
    if(x == finx && y == finy) {
        best_time = min(tiempo, best_time);
        return;
    }

    if(dir == 1) {
        g(x, y+1, 1, tiempo+1);
    } else {
        g(x, y+1, 1, tiempo+5);
    }

    if(dir == 3) {
        g(x, y-1, 3, tiempo+1);
    } else {
        g(x, y-1, 3, tiempo+5);
    }

    if(dir == 4) {
        g(x-1, y, 4, tiempo+1);
    } else {
        g(x-1, y, 4, tiempo+5);
    }

    if(dir == 2) {
        g(x+1, y, 2, tiempo+1);
    } else {
        g(x+1, y, 2, tiempo+5);
    }

    /*ret = g(x, y+1, 1, tiempo+1);
    if(ret != inf) {
        if(dir == 1)
            ans = min(ans, ret+1);
        else
            ans = min(ans, ret+5);
    }
    ret = g(x, y-1, 3, tiempo+1);
    if(ret != inf) {
        if(dir == 3)
            ans = min(ans, ret+1);
        else
            ans = min(ans, ret+5);
    }
    ret = g(x-1, y, 4, tiempo+1);
    if(ret != inf) {
        if(dir == 4)
            ans = min(ans, ret+1);
        else
            ans = min(ans, ret+5);
    }
    ret = g(x+1, y, 2, tiempo+1);
    if(ret != inf) {
        if(dir == 2)
            ans = min(ans, ret+1);
        else
            ans = min(ans, ret+5);
    }*/

    // return dp[x][y][dir] = ans;
}

void bfs(ll u, ll v, ll tiempo) {
    if(u < 0 || u >= MAX || v < 0 || v >= MAX) return;
    if(obs[u][v] == 1) return;
    if(u == finx && v == finy) {
        best_time = min(best_time, tiempo);
        return;
    }
    if(tiempo >= best_time) return;
    if(obs[u][v] == 2) return;
    obs[u][v] = 2;
    bfs(u-1, v, tiempo+5);
    bfs(u+1, v, tiempo+5);
    bfs(u, v-1, tiempo+5);
    bfs(u, v+1, tiempo+5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll tt, i, j, x, y, k, ans;
    cin >> tt;
    while(tt--) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                obs[i][j] = 0;
                for(k = 0; k < 5; k++)
                    dp[i][j][k] = -1;
            }
        }
        cin >> inix >> iniy;
        cin >> finx >> finy;
        inix = f(inix);
        iniy = f(iniy);
        finx = f(finx);
        finy = f(finy);
        cin >> k;
        for(i = 0; i < k; i++) {
            cin >> x >> y;
            x = f(x); y = f(y);
            obs[x][y] = 1;
        }
        /*ans = g(inix, iniy, 1, 0);
        ans = min(ans, g(inix, iniy, 2, 0));
        ans = min(ans, g(inix, iniy, 3, 0));
        ans = min(ans, g(inix, iniy, 4, 0));
        */
       best_time = inf;
       ll dx = 3000;
       best_time = inf;
       // cout << "ini1" << endl;
       bfs(inix, iniy, 0);
       if(best_time == inf) {
           cout << "-1\n";
           continue;
       }
       best_time = min(best_time, dx);
       //  cout << "ini2" << " " << best_time << endl;
       g(inix, iniy, 1, 0);
       g(inix, iniy, 2, 0);
       g(inix, iniy, 3, 0);
       g(inix, iniy, 4, 0);

        if(best_time == dx) cout << "-1\n";
       else cout << best_time << "\n";
       // return 0;
       // cout << endl;
    }
    
    return 0;
}