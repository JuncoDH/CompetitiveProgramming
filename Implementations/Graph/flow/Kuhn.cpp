// Maximum matching in a bipartite graph. (Also max flow).
// n1 size of Set1, complexity is O(n1*n1*n2).
// Set1 edges are [0, n1). Set2 edges are [0, n2).
class Kuhn{
    int n1, n2;
    vector<vi> graph;
    vector<bool> used;
    bool dfs(int u) {
        for(auto v : graph[u]) {
            if(used[v]) continue;
            used[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    public:
    vi match;
    Kuhn(int _n1, int _n2) {
        n1 = _n1; n2 = _n2;
        graph.assign(n1, vi());
        match.assign(n2, -1);
    }
    void add_edge(int u, int v) { // edge u->v (capacity 1).
        graph[u].pb(v);
    }
    int get_max_match() {
        int i, ans = 0;
        vector<bool> used1(n1, false);
        for(i = 0; i < n1; i++) { // Start with random match.
            for(auto v : graph[i]) { // Improves time.
                if(match[v] == -1) continue;
                match[v] = i;
                used1[i] = true;
                break;
            }
        }
        for(i = 0; i < n1; i++) {
            if(used1[i]) continue;
            used.assign(n2, false);
            dfs(i);
        }
        for(i = 0; i < n2; i++) {
            if(match[i] != -1) { // Edge (match[i], i).
                ans++;
                // echo(match[i], i);
            }
        }
        return ans;
    }
};

