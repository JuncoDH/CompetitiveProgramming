struct Query {
    // [l..r], id is the query id.
    int l = 0, r = 0, id = 0;
};
bool Query_cmp(Query const& a, Query const& b) {
    return a.r < b.r;
}
// Number of distinct numbers in the subarray [l..r].
// Answer offline, sort the queries by ending r. Every element will have one 1 in the bit
// in its rightmost ocurrence, so it will count one time when querying the bit query[l..r]
// and zero times if the rightmost ocurrence is < l.
void num_distinct_nums() {
    vi v = {1, 1, 2, 1, 3};
    vector<Query> vq = { {0, 4, 0}, {1, 3, 1}, {2, 4, 2} };
    int qnum = 0, n, qn;
    vi last_update(MAX, -1);
    Bit bit(MAX, 0);
    n = v.size();
    qn = vq.size();
    vi ans(qn);
    sort(vq.begin(), vq.end(), Query_cmp);
    for(int i = 0; i < n; i++) {
        if(last_update[v[i]] != -1) {
            bit.update(last_update[v[i]], -1);
        }
        last_update[v[i]] = i;
        bit.update(i, 1);
        while(qnum < qn && vq[qnum].r == i) {
            ans[vq[qnum].id] = bit.query(vq[qnum].r);
            if(vq[qnum].l > 0)
                ans[vq[qnum].id] -= bit.query(vq[qnum].l - 1);
            ++qnum;
        }
    }
    // echo(ans);
}

