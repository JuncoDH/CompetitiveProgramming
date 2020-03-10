//O(V^2*E) max flow algorithm. For bipartite matching O(sqrt(V)*E), always faster than Edmond-Karp.
//Creates layer's graph with a BFS and then it tries all possibles DFS, branching while the path doesn't reach the sink
struct EdgeFlow {
    ll u, v;
    ll cap, flow = 0; //capacity and current flow
    EdgeFlow(ll _u, ll _v, ll _cap) : u(_u), v(_v), cap(_cap) { }
};

struct Dinic {
    vector<EdgeFlow> edge; //keep the edges
    vector<vll> graph; //graph[u] is the list of their edges
    ll n, n_edges = 0;
    ll source, sink, inf_flow = inf;
    vll lvl; //lvl of the node to the source
    vll ptr; //ptr[u] is the next edge you have to take in order to branch the DFS
    queue<ll> q;

    Dinic(ll _n, ll _source, ll _sink) : n(_n), source(_source), sink(_sink) { //n nodes
        graph.assign(_n, vll());
    }

    void add_edge(ll u, ll v, ll flow) { //u->v with cost x
        EdgeFlow uv(u, v, flow), vu(v, u, 0);
        edge.pb(uv);
        edge.pb(vu);
        graph[u].pb(n_edges);
        graph[v].pb(n_edges+1);
        n_edges += 2;
    }

    bool BFS() {
        ll u;
        while(q.empty() == false) {
            u = q.front(); q.pop();
            for(auto el : graph[u]) {
                if(lvl[edge[el].v] != -1) {
                    continue;
                }
                if(edge[el].cap - edge[el].flow <= 0) {
                    continue;
                }
                lvl[edge[el].v] = lvl[edge[el].u] + 1;
                q.push(edge[el].v);                
            }
        }

        return lvl[sink] != -1;
    }

    ll dfs(ll u, ll min_flow) {
        if(u == sink) return min_flow;
        ll pushed, el;
        for(;ptr[u] < (int)graph[u].size(); ptr[u]++) { //if you can pick ok, else you crop that edge for the current bfs layer
            el = graph[u][ptr[u]];
            if(lvl[edge[el].v] != lvl[edge[el].u] + 1 || edge[el].cap - edge[el].flow <= 0) {
                continue;
            }
            pushed = dfs(edge[el].v, min(min_flow, edge[el].cap - edge[el].flow));
            if(pushed > 0) {
                edge[el].flow += pushed;
                edge[el^1].flow -= pushed;
                return pushed;
            }
            
        }
        return 0;
    }

    ll max_flow() {
        ll flow = 0, pushed;
        while(true) {
            lvl.assign(n, -1);
            lvl[source] = 0;
            q.push(source);
            if(!BFS()) {
                break;
            }

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
