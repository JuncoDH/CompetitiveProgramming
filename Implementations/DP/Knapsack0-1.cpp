vll v, w;// v are values (+), w are weight (-) 
const int MAX_VALUE = 5005; //max size of the knapsack value
ll dp[MAX_VALUE];
//dp[i] is the minimum cost to spend buying items that the sum of their values is i. 
void knapsack() {
    ll i, j, n = v.size();
    for(i = 0; i < MAX_VALUE; i++) dp[i] = inf;
    dp[0] = 0;
    for(i = 0; i < n; i++) {
        if(w[i] == inf) continue;
        for(j = MAX_VALUE-1; j >= 0; j--) {
            if(j + v[i] < MAX_VALUE && dp[j] != inf) dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
        }
    }
}
