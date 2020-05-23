const ll MAX = 3*1e5 + 5;
//vll t(4*MAX, 0), a(MAX);
vll t, a;
ll n;

void build(ll k, ll l, ll r) {
    if(l == r) {t[k] = a[l]; return;}
    ll mid = (l + r) >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid + 1, r);
    t[k] = max(t[k<<1], t[k<<1|1]);
}

void update(ll k, ll l, ll r, ll p, ll x) {
    if(l == r) {
        if(l == p) {t[k] = x;}
        return;
    }
    ll mid = (l + r) >> 1;
    if(p <= mid) update(k<<1, l, mid, p, x);
    else update(k<<1|1, mid+1, r, p, x);
    t[k] = max(t[k<<1], t[k<<1|1]);
}

ll query(ll k, ll l, ll r, ll ql, ll qr) {
    if(ql <= l && r <= qr) return t[k];
    if(qr < l || r < ql) return 0;
    ll mid = (l + r) >> 1;
    ll qa = query(k<<1, l, mid, ql, qr);
    ll qb = query(k<<1|1, mid + 1, r, ql, qr);
    if(qr <= mid) return qa;
    if(mid+1 <= l) return qb;
    return max(qa, qb);
}

void update(ll p, ll x) {
    update(1, 0, n-1, p, x);
}

ll query(ll ql, ll qr) {
    return query(1, 0, n-1, ql, qr);
}
