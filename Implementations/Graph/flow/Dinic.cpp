class Edge {
    public:
    int u, v;
    int cap, flow = 0; // Capacity and current flow.
    Edge(int const _u, int const _v, int const _cap) : u(_u), v(_v), cap(_cap) { }
};
// O(V^2 * E). For unit edge capacity O(sqrt(V)*E).
class Dinic {
    vector<Edge> edge;
    vector<vi> graph;
    int n, n_edges = 0;
    int source, sink, inf_flow = INT_MAX;
    vi lvl; // lvl of the node to the source.
    vi ptr; // ptr[u] is the next edge you have to take in order to branch the DFS.
    queue<ll> q;
    bool BFS() {
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto const& el : graph[u]) {
                if(lvl[edge[el].v] != -1) continue;
                if(edge[el].cap - edge[el].flow <= 0) continue;
                lvl[edge[el].v] = lvl[edge[el].u] + 1;
                q.push(edge[el].v);
            }
        }
        return lvl[sink] != -1;
    }
    int dfs(int const u, int const min_flow) {
        if(u == sink) return min_flow;
        int pushed, el;
        for(; ptr[u] < (int)graph[u].size(); ptr[u]++) { // If you can pick ok, else you crop that edge for the current bfs layer.
            el = graph[u][ptr[u]];
            if(lvl[edge[el].v] != lvl[edge[el].u] + 1 || edge[el].cap - edge[el].flow <= 0) {
                continue;
            }
            pushed = dfs(edge[el].v, min(min_flow, edge[el].cap - edge[el].flow));
            if(pushed > 0) {
                edge[el].flow += pushed;
                edge[el ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    public:
    Dinic(int const _n, int const _source, const int _sink) : n(_n), source(_source), sink(_sink) {
        graph.assign(_n, vi());
    }
    void add_edge(int const u, int const v, int const flow) { // Add u->v edge.
        Edge uv(u, v, flow), vu(v, u, 0); // Not multiedge.
        edge.pb(uv);
        edge.pb(vu);
        graph[u].pb(n_edges);
        graph[v].pb(n_edges + 1);
        n_edges += 2;
    }
    int max_flow() { // It consumes the graph.
        int flow = 0, pushed;
        while(true) {
            lvl.assign(n, -1);
            lvl[source] = 0;
            q.push(source);
            if(!BFS()) break;
            ptr.assign(n, 0);
            while(true) {
                pushed = dfs(source, inf_flow);
                if(!pushed) break;
                flow += pushed;
            }
        }
        return flow;
    }
};

