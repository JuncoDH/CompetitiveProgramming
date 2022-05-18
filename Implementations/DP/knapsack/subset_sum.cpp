const int MAX_C = 1000005;
vll w; // n items such that sum(w[i]) == C.
// Check if for k in [1..C] exists a subset of w with sum == k.
// Complexity O(n log n + c sqrt(c)/32).
void subset_sum() {
    vll w_optimized; // Keep O(sqrt(C)) elements instead of N.
    sort(w.begin(), w.end());
    ll sum, last_2;
    int i, cnt = 1, n = w.size();
    for(i = 1; i < n; i++) {
        if(w[i] != w[i-1]) {
            sum = 0; last_2 = 0; // (1, 2, 4, 8, rest).
            while(sum + (1ll<<last_2) <= cnt) {
                cnt -= 1ll<<last_2;
                w_optimized.pb((1ll<<last_2)*w[i-1]);
                sum += 1ll<<last_2;
                last_2++;
            }
            if(cnt > 0) w_optimized.pb(cnt*w[i-1]);
            cnt = 0;
        }
        cnt++;
    }
    sum = 0; last_2 = 0;
    while(sum + (1ll<<last_2) <= cnt) {
        cnt -= 1ll<<last_2;
        w_optimized.pb((1ll<<last_2)*w[i-1]);
        sum += 1ll<<last_2;
        last_2++;
    }
    if(cnt > 0) w_optimized.pb(cnt*w[i-1]);
    w = w_optimized; n = w.size();
    bitset<MAX_C> bs; // bs[k] is the answer for each k.
    bs.set(0);
    for(i = 0; i < n; i++) {
        bs = bs | bs << w[i];
    }
    for(i = (nn-1)/2; i >= 0; i--) {
        if(bs[i]) {
            ansi = i;
            break;
        }
    }
}

