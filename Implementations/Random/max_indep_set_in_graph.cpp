// Need a bidirectional graph, O(n) (unidirectional the solution could be even better)
// -1 don't know, 0 the node can't be in the independing set, 1 the node is in the independing set
int indep[MAX + 5]; 
bool visited[MAX + 5];
ll cont; // Cont the number of 1's in the indep array
// Find random an independent set and hope is big enough for the problem.
// Example: ceil(k/2) nodes if the graph don't contain cycles with length at most k.
void max_indep_set_random(ll u, bool add) { //call random_max_indep(rand()%n, true)
    visited[u] = true;
    for(auto v : graph[u]) if(indep[v] == 1) {add = false; break;} // Can't take u as indep
    if(add == true) {
        for(auto v : graph[u]) indep[v] = 0; // Mark the neighbours as impossible
        if(indep[u] == -1) indep[u] = 1, cont++; // Add to the independent set
    }
    random_shuffle(graph[u].begin(), graph[u].end()); // To prevent local maximum
    for(auto v : graph[u]) {
        if(visited[v]) continue;
        max_indep_set_random(v, add^1);
    }
}
