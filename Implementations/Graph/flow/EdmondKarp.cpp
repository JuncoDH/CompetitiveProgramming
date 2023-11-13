// Edmond Karp implementation of Ford Fulkerson algorithm.
class EdmondKarp{
    vector<vi> graph; // O(V^2) size.
    vector<set<int>> ady_list; // Convert O(V^2) to O(E).
    int n;
    vi parent;
    bool bfs(int const s, int const t) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto const& v : ady_list[u]) {
                if(!visited[v] && graph[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    if(v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    public:
    EdmondKarp(int const _n) {
        n = _n;
        graph.assign(n, vi(n, 0));
        ady_list.assign(n, set<int>());
        parent.assign(n, 0);
    }
    void add_edge(int const u, int const v, int const w) { // Add u->v edge.
        graph[u][v] += w; // Multiple edges.
        if(graph[u][v]) ady_list[u].insert(v);
        else ady_list[u].erase(v);
    }
    // Source s to sink t. Complexity O(V*E*E).
    int max_flow(int const s, int const t) {
        int ans = 0, v;
        while(bfs(s, t)) {
            int m = INT_MAX; // The lowest edge founded in the BFS.
            for(v = t; v != s; v = parent[v]) {
                m = min(m, graph[parent[v]][v]);
            }
            ans += m;
            for(v = t; v != s; v = parent[v]) {
                add_edge(parent[v], v, -m);
                add_edge(v, parent[v], m);
            }
        }
        return ans;
    }
};

