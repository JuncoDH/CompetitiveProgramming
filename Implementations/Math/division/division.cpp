// Save first n_dec decimals of D/d. Truncated.
void divide(ll D, ll d, int n_dec, string &s) {
    ll i;
    s = to_string(D/d);
    if(!n_dec) return;
    s.pb('.');
    D %= d;
    for(i = 0; i < n_dec; i++) {
        D *= 10;
        s.pb(D/d + '0');
        D %= d;
    }
}
// 1.366666... pre period is 1.3 post period is 6.
void get_period(ll D, ll d, string &pre, string &post) {
    pre = to_string(D/d);
    post = "";
    D %= d;
    if(!D) return;
    pre.pb('.');
    int i, num;
    vi v, vpost;
    map<int, int> first_pos;
    for(i = 0;; i++) {
        if(!D) break;
        if(first_pos.count(D)) {
            num = first_pos[D];
            while((int)v.size() != num) {
                vpost.pb(v.back());
                v.pop_back();
            }
            break;
        }
        first_pos[D] = v.size();
        D *= 10;
        v.pb(D/d);
        D %= d;
    }
    for(auto el : v) pre.pb(el + '0');
    if(!D) return;
    for(i = (int)vpost.size()-1; i >= 0; i--)
        post.pb(vpost[i] + '0');
}

