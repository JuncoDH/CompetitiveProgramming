// You can use it when you can extend / shrink interval by 1 element.
// O((Q+N)sqrt(N)), is sqrt decomposition.
class Query{
    static const int BLOCK = 170; // sqrt(n) +-;
    public:
    int l, r, id;
    Query() = default;
    Query(int _l, int _r, int _id) {
        l = _l; r = _r; id = _id;
    }
    bool operator < (const Query &other) const {
        if(l/BLOCK != other.l/BLOCK) {
            return l/BLOCK < other.l/BLOCK;
        }
        if(r != other.r) return r < other.r;
        return l < other.l;
    }
};
// Calculate the num of different numbers in [l, r].
class Mo{
    static const int MAX_FREQ = 1e6+5;
    vector<Query> vquery;
    vll v; // Input vector.
    int currL = 0; // currAns represent answer for the
    int currR = -1;// interval [currL, currR].
    int currAns = 0;
    vi freq;
    void add(int i) {
        freq[v[i]]++;
        if(freq[v[i]] == 1) currAns++; 
    }
    void remove(int i) {
        freq[v[i]]--;
        if(freq[v[i]] == 0) currAns--;
    }
    public:
    Mo(vll &_v) {
        v = _v;
    }
    void insert_query(int l, int r, int id) {
        vquery.pb(Query(l, r, id));
    }
    vi solve() {
        int i, n = vquery.size();
        freq.assign(MAX_FREQ, 0);
        vector<pii> ans(n);
        sort(vquery.begin(), vquery.end());
        for(i = 0; i < n; i++) {
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
        for(i = 0; i < n; i++) {
            answer[i] = ans[i].se;
        }
        return answer;
    }
};
