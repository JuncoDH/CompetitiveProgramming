//Tested AC in Diciembre Dora, Ada 2020, not 100% sure of correctness
const ll MAX = 2*1e5+5;
vll graph[MAX];
ll n, m;
ll cont = 0, discovered[MAX], low[MAX], component[MAX]; //number of remaining components if erasing i node, initialize to 1
//u is articulation point if component[u] > 1 

void add_edge(ll u, ll v) {
    graph[u].pb(v);
    graph[v].pb(u);
}

void dfs(ll u, ll p) {
    ll child = 0; //number of childs in the dfs tree
    if(discovered[u] != -1) return;
    discovered[u] = cont;
    low[u] = cont++;
    for(auto el : graph[u]) {
        if(el == p) continue;
        if(discovered[el] == -1)  {
            child++;
            if(p == -1 && child > 1) {component[u]++;} //case root is articulation point
            dfs(el, u);
            if(discovered[u] < low[el]) {
                //echo( u, el); //bridge
                //u--el is a bridge, u is articulation if u is not a leaf, el is articulation if el is not a leaf
                component[u]++; component[el]++;
            }
        }
        low[u] = min(low[u], low[el]);
	//maybe should be if discovered[el] != -1 low[u] = min(low[u], disc[el]);
    }
}
//for(i = 0; i < MAX; i++) component[i] = min(component[i], (ll)graph[i].size()); //add at the end

void show(ll _n) { //debugging purpose
   
    for(int i= 0; i < _n; i++) {
        cout << i << " ";
    }
     cout << "discovered: " << endl;

    for(int i= 0; i < _n; i++) {
        cout << discovered[i] << " ";
    }
    cout << "------- low: " << endl;
    for(int i= 0; i < _n; i++) {
        cout << low[i] << " ";
    }
    cout << "------- component: " << endl;
    for(int i= 0; i < _n; i++) {
        cout << component[i] << " ";
    }
    cout << endl;
}
