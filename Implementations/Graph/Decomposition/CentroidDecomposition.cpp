const int MAX = 1e5+5;
int n;
vi graph2[MAX], decomposed[MAX]; // input bidirectional tree and centroid decomposed tree, rooted at CD() return
int q[MAX]; // queue

struct nodes {
    int subtree; // size of the subtree
    int parent; // parent in the decomposed tree
    int level; // level in the tree. Useful to do LCA just going up O(log n)
    bool is_centroid; // visited / used boolean
} node[MAX];

void dfs_size(int u, int p) { // fill subtree
    node[u].subtree = 1;
    for(auto v : graph2[u]) {
        if(v == p) continue;
        if(node[v].is_centroid) continue;
        dfs_size(v, u);
        node[u].subtree += node[v].subtree;
    }
}

int get_centroid(int u, int p, int n_sub) { // return the centroid
    for(auto v : graph2[u]) {
        if(v == p) continue;
        if(node[v].is_centroid) continue;
        if(node[v].subtree > n_sub/2) return get_centroid(v, u, n_sub);
    }
    return u;
}

int CD() { //fill decomposed, no need preprocess. Find centroid, split, recurse (with BFS)
    dfs_size(0, -1);
    int root = get_centroid(0, -1, n), u, v, rd = 0, wr = 0;
    node[root].is_centroid = true;
    node[root].parent = -1;
    node[root].level = 0;
    q[wr++] = root;
    while(rd < wr) {
        u = q[rd++];
        for(auto el : graph2[u]) {
            if(node[el].is_centroid) continue;
            dfs_size(el, -1);
            v = get_centroid(el, -1, node[el].subtree);
            node[v].is_centroid = true;
            node[v].parent = u;
            node[v].level = node[u].level + 1;
            decomposed[u].pb(v);
            q[wr++] = v;
        }
    }
    return root;
}
