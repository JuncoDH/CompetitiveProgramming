vll bit;
ll bit_n;
void ini(ll n) {bit_n = n; bit.assign(bit_n + 1, 0);}
void update(ll i, ll x) {for(i++; i <= bit_n; i += LSB(i)) bit[i] += x;}
ll query_sum(ll i) {ll sum = 0; for(i++; i > 0; i -= LSB(i)) sum += bit[i]; return sum;}
/*k-th smallest element set in the bit*/
ll k_element(ll k) {
    ll l = 0, r = bit_n -1, mid, sum;
    while(l < r) {
        mid = (l + r)/2;
        sum = query_sum(mid);
        if(sum >= k) r = mid;
        else l = mid + 1;
    }
    return r;
}