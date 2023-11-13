// vpos[i] is all the positions of element i in the vector.
vector<vll> get_vector_position(vll const& v) {
    int n = v.size();
    vector<vll> vpos(n+1, vll()); // Elements [0, n].
    for(int i = 0; i < n; i++) {
        vpos[v[i]].pb(i);
    }
    return vpos;
}

