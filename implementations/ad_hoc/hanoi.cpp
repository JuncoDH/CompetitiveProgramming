// Example of colors.
// Verde = 1.
// Rojo = 2.
// Azul = 3.
// Rosa = 4.
// Amarillo = 5.

// Move the disks to the first stack v[0].
// The bottom of the pile is the left most element, and the top is the right most element.
vi goal = {1, 3, 5, 4, 2};
set<vector<vi>> visited;
vector<string> hanoi() {
    vector<vi> v = {{}, {}, {}}; // Initial state.
    queue<pair<vector<vi>, vector<string>>> q;
    q.push(mp(v, vector<string>()));
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        v = u.fi;
        if (visited.count(v)) continue;
        visited.insert(v);
        if (v[0] == goal) {
            return u.se;
        }
        for (int i = 0; i < (int)v.size(); i++) { // Move from i to j.
            if (v[i].empty()) continue;
            for (int j = 0; j < (int)v.size(); j++) {
                if (i == j) continue;
                v[j].pb(v[i].back());
                v[i].pop_back();
                u.se.pb(to_string(i + 1) + " -> " + to_string(j + 1));
                q.push(mp(v, u.se));
                u.se.pop_back();
                v[i].pb(v[j].back());
                v[j].pop_back();
            }
        }
    }
    return {};
}

