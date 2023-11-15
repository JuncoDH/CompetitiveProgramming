// Floyd-Warshall O(n^3).
// dist is an adjacency matrix with INT_MAX if there aren't a conexion from i to j.
// Try to actualize k times the minimum distance.
for(k = 0; k < n; ++k) {
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
       }
    }
}

