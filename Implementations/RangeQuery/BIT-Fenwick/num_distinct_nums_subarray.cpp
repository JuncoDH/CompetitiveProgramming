struct Query{
    //[l..r], id is the query id
    int l, r, id;
};

bool Query_cmp(Query a, Query b) {
    return a.r < b.r;
}

vi Bit;
const int MAX = 3*1e5 + 5;

void update(ll id, ll val) {
    for(id++; id < MAX + 1; id += LSB(id)) {
        Bit[id] += val;
    }
}
ll query(ll id) {
    ll sum = 0;
    for(id++; id > 0; id -= LSB(id)) {
        sum += Bit[id];
    }
    return sum;
}

// Number of distinct numbers in the subarray [l..r]. 
// Answer offline, sort the queries by ending r. Every element will have one 1 in the bit
// in its rightmost ocurrence, so it will count one time when querying the bit query[l..r]
// and zero times if the rightmost ocurrence is < l.
void num_distinct_nums() {
    vi v = {1, 1, 2, 1, 3};
    vector<Query> vq = {{0, 4, 0}, {1, 3, 1}, {2, 4, 2}};
    int qnum = 0, i, n, qn;
    vi last_update(MAX, -1);
    Bit.assign(MAX, 0);
    n = v.size();
    qn = vq.size();
    vi ans(qn);

    sort(vq.begin(), vq.end(), Query_cmp);

    for(i = 0; i < n; i++) {
        if(last_update[v[i]] != -1) {
            update(last_update[v[i]], -1);
        }
        last_update[v[i]] = i;

        update(i, 1);

        while(qnum < qn && vq[qnum].r == i) {
            ans[vq[qnum].id] = query(vq[qnum].r);
            if(vq[qnum].l > 0)
                ans[vq[qnum].id] -= query(vq[qnum].l - 1);
            ++qnum;
        }
    }
    echo(ans);
}

