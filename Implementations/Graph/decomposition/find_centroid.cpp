int subtree_sz[MAX];// Number of nodes in the subtree u, rooted at 1.
int mn = MAX; // Min {Max{sz(T_i)}} and T_i are the trees created when cutting node i.
vi centroid; // The centroids. Always there are 1 centroid or 2: x and y, and edge x-y exist.
vector<pii> subtree[MAX]; // subtree[u] = (fi, se) fi is one child of u and se is the size of that subtree.
void fill_sz(int u, int p) { // Recursive fill subtree array.
    subtree_sz[u] = 1;
    for(auto v : graph[u]) {
        if(v == p) continue;
        fill_sz(v, u);
        subtree_sz[u] += subtree_sz[v];
        subtree[u].pb(mp(v, subtree_sz[v]));
    }
    if(p != -1)
        subtree[u].pb(mp(p, n-subtree_sz[u])); // n is the number of nodes of the graph.
    int mx = 0;
    for(auto el : subtree[u]) mx = max(mx, el.se);
    mn = min(mn, mx);
}

// 1-indexed!
void find_centroid() { // fill vi centroid.
    int mx = 0, i;
    mn = MAX;
    centroid.clear();
    for(i = 1; i <= n; i++) subtree[i].clear();
    fill_sz(1, -1);
    for(i = 1; i <= n; i++) {
        mx = 0;
        for(auto el : subtree[i]) {
            mx = max(mx, el.se);
        }
        if(mx == mn) centroid.pb(i);
    }
}
