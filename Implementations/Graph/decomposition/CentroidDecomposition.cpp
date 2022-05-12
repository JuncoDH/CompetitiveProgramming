class node{
    public:
    int subtree = 1; // Number of nodes. Dont use it.
    int parent = -1; // To go upwards in the cd_graph.
    int lvl = 0;
    bool is_centroid = false;
};
// Instead of asking for a path u -> v, ask for u -> lca(u, v) -> v.
// The decomposed tree has heigh O(log n).
class CentroidDecomposition{
    void dfs_size(int u, int p) {
        vn[u].subtree = 1;
        for(auto v : graph[u]) {
            if(v == p || vn[v].is_centroid) continue;
            dfs_size(v, u);
            vn[u].subtree += vn[v].subtree;
        }
    }
    int get_centroid(int u, int p, int n_subtree) {
        for(auto v : graph[u]) {
            if(v == p || vn[v].is_centroid) continue;
            if(vn[v].subtree > n_subtree/2)
                return get_centroid(v, u, n_subtree);
        }
        return u;
    }
    vector<vi> graph; // Input graph.
    public:
    vector<node> vn;
    int root; // Root of the cd_graph;
    vector<vi> cd_graph; // directed CD graph root -> edges.
    CentroidDecomposition(vector<vi> &_graph) {
        graph = _graph;
        int u, v, n = graph.size();
        vn.assign(n, node());
        cd_graph.assign(n, vi());
        dfs_size(0, -1);
        root = get_centroid(0, -1, vn[0].subtree);
        queue<int> q;
        vn[root].is_centroid = true;
        q.push(root);
        while(!q.empty()) {
            u = q.front(); q.pop();
            for(auto el : graph[u]) {
                if(vn[el].is_centroid) continue;
                dfs_size(el, -1);
                v = get_centroid(el, -1, vn[el].subtree);
                vn[v].is_centroid = true;
                vn[v].parent = u;
                vn[v].lvl = vn[u].lvl + 1;
                cd_graph[u].pb(v);
                q.push(v);
            }
        }
    }
    // The centroid is the node that when removing, all its
    // subtrees have <= n/2 nodes. It can be AT MOST 2 centroids.
    int get_centroid() {
        dfs_size(0, -1);
        return get_centroid(0, -1, vn[0].subtree);
    }
    int lca(int u, int v) {
        while(vn[u].lvl > vn[v].lvl) u = vn[u].parent;
        while(vn[v].lvl > vn[u].lvl) v = vn[v].parent;
        while(u != v) u = vn[u].parent, v = vn[v].parent;
        return u;
    }
};

