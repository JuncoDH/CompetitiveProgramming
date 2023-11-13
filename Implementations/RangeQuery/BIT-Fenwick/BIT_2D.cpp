template<typename T>
class BIT_2D {
    vector<vector<T>> Bit2D;
    int n = 0, m = 0;
    public:
    BIT_2D() = default;
    BIT_2D(int const _n, int const _m) {
        n = _n;
        m = _m;
        Bit2D.assign(n + 1, vector<T>(m + 1, 0));
    }
    explicit BIT_2D(vector<vector<T>> const& v) {
        n = v.size();
        m = v[0].size();
        Bit2D.assign(n + 1, vector<T>(m + 1, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                update(i, j, v[i][j]);
        }
    }
    void update(int const l, int const r, T const val) {
        for(int i = l + 1; i <= n; i += LSB(i)) {
            for(int j = r + 1; j <= m; j += LSB(j)) {
                Bit2D[i][j] += val;
            }
        }
    }
    T sum(int const l, int const r) const {
        T ans = 0;
        for(int i = l + 1; i > 0; i -= LSB(i)) {
            for(int j = r + 1; j > 0; j -= LSB(j)) {
                ans += Bit2D[i][j];
            }
        }
        return ans;
    }
    T sum(int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2); // (x1, y1) is the bottom-left corner.
        return sum(x1 - 1, y1 - 1) + sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2);
    }
};

