// Sparse Table, table[i][j] = covers [i, i + 2^j - 1], range 2^j.
// CAN'T UPDATE VALUES.
const ll MAX = 1e5;
const int LOG2_MAX = 22; // log2(MAX).
ll table[MAX][LOG2_MAX]; // Outside class.
template<typename T>
class SparseTable {
    int n;
    T f(T a, T b) {
        return min(a, b);
    }
    public:
    SparseTable(vector<T> &v) {
        int i, j;
        n = v.size();
        for(i = 0; i < n; ++i) table[i][0] = v[i];
        
        for(j = 1; j < LOG2_MAX; ++j){
            for(i = 0; i < n; ++i){
                if(i + (1ll << (j - 1)) >= n) break;
                table[i][j] = f(table[i][j - 1], table[i + (1ll << (j - 1))][j - 1]);
            }
        }
    }
    // [ql..qr], [0..n-1].
    T query(int ql, int qr) {
        int lg2_dif = -1, num = qr - ql;
        if(ql == qr) return table[ql][0];
        while(num) lg2_dif++, num >>= 1;
        return f(table[ql][lg2_dif], table[qr - (1ll << lg2_dif) + 1][lg2_dif]);
    }
};

