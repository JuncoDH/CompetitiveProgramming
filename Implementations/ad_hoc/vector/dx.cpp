// Use v[i + z * el.fi][j + z * el.se].
vector<pii> dx4 = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
vector<pii> dx8 = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };
ll n, m;
bool is_valid(ll const i, ll const j) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}

