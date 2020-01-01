// SWERC 2015 - Promotions
// Approach: DFS to find the successors of each node. Then, use this information
//           to find the number of predecessors as well. O(P*N + N^2)
// Author: Miguel Oliveira
#include <cstdio>
#include <cstring>
const int MAX = 5002;
int adj[MAX][MAX], nedges[MAX], npred[MAX], N, A, B, nchildren[MAX];
char is_child[MAX][MAX], done[MAX];

void Go(int i) {
  done[i] = 1;
  for (int j = 0; j < nedges[i]; ++j) {
    int w = adj[i][j];
    if (!done[w])
      Go(w);
    is_child[i][w] = 1;           // The successors of 'w' are also
    for (int k = 0; k < N; ++k)   // successors of 'i'.
      is_child[i][k] |= is_child[w][k];
  }
}
int main() {
  int i, j, P;
  scanf("%d %d %d %d", &A, &B, &N, &P);
  while (P--) {
    scanf("%d %d", &i, &j);
    adj[i][nedges[i]++] = j;
  }
  // Find the successors of each node.
  for (i = 0; i < N; ++i) 
    if (!done[i])
      Go(i);
  // For each pair (i, j) if 'j' is a successor of 'i', then count 'i' as predecessor of 'j'.
  for (i = 0; i < N; ++i)
    for (j = 0; j < N; ++j) 
      if (is_child[i][j]) {
        nchildren[i]++;
        npred[j]++;
      }
  int mustA = 0, mustB = 0, cant = 0;
  for (i = 0; i < N; ++i) {
    mustA += A >= (N - nchildren[i]);
    mustB += B >= (N - nchildren[i]);
    cant += npred[i] >= B;
  }
  printf("%d\n%d\n%d\n", mustA, mustB, cant);
  return 0;
}
