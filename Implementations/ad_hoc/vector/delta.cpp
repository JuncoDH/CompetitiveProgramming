// v[i+z*el.fi][j+z*el.se]
vector<pii> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},     {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
ll n, m;
bool is_valid(ll i, ll j) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}

