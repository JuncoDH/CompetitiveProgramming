//Tarjan algorithm for finding Srontly Connected Components in a graph in O(n). Is faster than Kosaraju
//make one DFS adding nodes to a stack. The head of a SCC will have low[u] = discover[u]
vector<vi> graph;
vi discover, low;
vector<bool> onStack;
stack<int> st;
int Time = 0;
void add(int u, int v){
    graph[u].pb(v);
}
void ini(int n){
    graph.assign(n, vi());
    discover.assign(n, -1);
    low.assign(n, -1);
    onStack.resize(n, false);
    st = stack<int>();
    Time = 0;
}
// call for(i = 0; i < n; i++) if(discover[i] == -1) dfs(i);
void dfs(int u){
    low[u] = discover[u] = ++Time;
    onStack[u] = true;
    st.push(u);
    for(auto it : graph[u]){
        if(discover[it] == -1) dfs(it);        
        if(onStack[it] == true) low[u] = min(low[u], low[it]);//if onStack[it] = false then it belong to another SCC previosly processed        
    }
    if(low[u] == discover[u]){ //it's a head node
        while(true){
            cout << st.top() << ".";
            low[st.top()] = low[u];
            onStack[st.top()] = false;
            if(st.top() == u){
                st.pop();
                break;
            }
            st.pop();
        }
        cout << endl;
    }
}

