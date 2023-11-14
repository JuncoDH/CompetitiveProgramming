constexpr int MAX_N = 4001;
vector<int> graph[MAX_N];
// Fills cycle vector with a path that creates an odd cycle.
// There exist a path from u to odd_cycle[0].
// Take care of self-edges: u --> u.
// The graph has odd cycle iff is not bipartite iff is no 2-coloreable.
vi odd_cycle;
int color[MAX_N]; // Color and number of components with each color.
vector<pii> n_set_component; //number of colors of each set in the i component.
int n_component, number_component[MAX_N];//the component the i node belongs.
bool rec(int const u, int const c) {
    if(color[u] != -1) {
        if(color[u] == c) return false;
        odd_cycle.pb(u);
        return true;
    }
    color[u] = c;
    number_component[u] = n_component;
    if(c == 0) n_set_component.back().fi++;
    else n_set_component.back().se++;
    for(auto const& el : graph[u]) {
        if(rec(el, c ^ 1)) {
            if(odd_cycle.size() > 1 && odd_cycle.back() == odd_cycle[0]) return true;
            odd_cycle.pb(u);
            return true;
        }
    }
    return false;
}
bool bipartite_color(int const n) {
    int i;
    odd_cycle.clear();
    for(i = 0; i < MAX_N; i++) color[i] = -1;
    for(i = 0; i < n; i++) {
        if(color[i] == -1) {
            n_set_component.pb({0, 0});
            rec(i, 0);
            n_component++;
            if(!odd_cycle.empty()) { // The graph is not bipartite.
                reverse(odd_cycle.begin(), odd_cycle.end());
                return false;
            }
        }
    }
    return true;
}

