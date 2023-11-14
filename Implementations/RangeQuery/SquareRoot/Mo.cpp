// You can use it when you can extend / shrink interval by 1 element.
// O((Q + N) sqrt(N)), is sqrt decomposition.
class Query {
    static constexpr int BLOCK = 170; // sqrt(n) + -;
    public:
    int l = 0, r = 0, id = 0;
    Query() = default;
    Query(int const _l, int const _r, int const _id) {
        l = _l; r = _r; id = _id;
    }
    bool operator < (Query const& other) const {
        if(l / BLOCK != other.l / BLOCK) {
            return l / BLOCK < other.l / BLOCK;
        }
        if(r != other.r) return r < other.r;
        return l < other.l;
    }
};
// Calculate the num of different numbers in [l, r].
class Mo {
    static constexpr int MAX_FREQ = 1e6 + 5;
    vector<Query> vquery;
    vll v; // Input vector.
    int currL = 0; // currAns represent answer for the
    int currR = -1; // interval [currL, currR].
    int currAns = 0;
    vi freq;
    void add(int const i) {
        freq[v[i]]++;
        if(freq[v[i]] == 1) currAns++;
    }
    void remove(int const i) {
        freq[v[i]]--;
        if(freq[v[i]] == 0) currAns--;
    }
    public:
    Mo() = default;
    explicit Mo(vll const& _v) {
        v = _v;
    }
    void insert_query(int const l, int const r, int const id) {
        vquery.pb(Query(l, r, id));
    }
    vi solve() {
        int n = vquery.size();
        freq.assign(MAX_FREQ, 0);
        vector<pii> ans(n);
        sort(vquery.begin(), vquery.end());
        for(int i = 0; i < n; i++) {
            while(currL < vquery[i].l) {
                remove(currL);
                currL++;
            }
            while(currL > vquery[i].l) {
                currL--;
                add(currL);
            }
            while(currR < vquery[i].r) {
                currR++;
                add(currR);
            }
            while(currR > vquery[i].r) {
                remove(currR);
                currR--;
            }
            ans[i] = mp(vquery[i].id, currAns);
        }
        sort(ans.begin(), ans.end());
        vi answer(n);
        for(int i = 0; i < n; i++) {
            answer[i] = ans[i].se;
        }
        return answer;
    }
};

