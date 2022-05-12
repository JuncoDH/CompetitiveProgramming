const int MAX_N1 = 1002; //number of workers
const int MAX_N2 = 2002; //number of items
int cost[MAX_N1][MAX_N2]; //cost matrix, entries >= 0
int u[MAX_N1+1], v[MAX_N2+1]; //potentials, always cost[i][j] >= u[i] + v[j]
int slack[MAX_N2+1]; //cost[i][j] - u[i] - v[j], always >= 0
int prevy[MAX_N2+1]; //edges of the current path: prev[j0] -> yx[prev[j0]] -> j0. Dont need to reset
bool used[MAX_N2+1]; //visited array 
int yx[MAX_N2+1]; //match of the j column
int n1=, n2=, INF = INT_MAX-1; //actual size of workers and items. 
//http://e-maxx.ru/algo/assignment_hungary
//Solves MINIMUM Assignment. For maximum change cost[i][j] to Max_entry - cost[i][j] and resize the answer.
//There are 1..n1 rows and 1..n2 columns, ALWAYS n1 <= n2. Complexity(n1 * n1*n2)
//The function use 1-index for variables because it creates a virtual vertex 0
int Hungarian() {
    int i, i0, j, j0, min_j, delta, ans;
    fill(u, u+n1+1, 0);
    fill(v, v+n2+1, 0);
    fill(yx, yx+n2+1, 0);
    for(i = 1; i <= n1; i++) { //Add row by row to the current matching
        yx[0] = i; //connect 0 of set 2 with vertex i
        j0 = 0; //i0 and j0 are the current selected row and column, i and j are just iterators
        fill(slack, slack+n2 + 1, INF);
        fill(used, used + n2 + 1, false);
        do { //while the alternating path is not augmenting path
            used[j0] = true;
            delta = INF;
            i0 = yx[j0];
            for(j = 1; j <= n2; j++) { //get the delta among all columns not used
                if(!used[j]) {
                    int cur = cost[i0-1][j-1] - u[i0] - v[j];
                    if(cur < slack[j]) {
                        slack[j] = cur, prevy[j] = j0;
                    }
                    if(slack[j] < delta) { //try if delta  == 0 break
                        delta = slack[j], min_j = j;
                    }
                }
            }
            for(j = 0; j <= n2; j++) { //add delta in set 1, subtract delta in set 2
                if(used[j]) u[yx[j]] += delta, v[j] -= delta;
                else slack[j] -= delta;
            }
            j0 = min_j;
        } while(yx[j0] != 0);
        do{ //invert the augmenting path
            yx[j0] = yx[prevy[j0]];
            j0 = prevy[j0];
        } while(j0);
    }
    ans = 0;
    for(j = 1; j <= n2; j++) { //recover solution. The matched edges are yx[j]-1 -> j-1
        if(yx[j])
            ans += cost[yx[j]-1][j-1];
    }
    return ans;
}
// THE ANS IS n1*M_factor - Hungarian().
int M_factor; // Change problem finding the minimum cost to maximum cost, that can be solved by Hungarian
void min_to_max() { //min in cost[i][j] = max in M - cost[i][j]. 
    int i, j;
    M_factor = 0;
    for(i = 0; i < n1; i++) {
        M_factor = max(M_factor, *max_element(cost[i], cost[i]+n2));
    }
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {
            cost[i][j] = M_factor - cost[i][j];
        }
    }
}

