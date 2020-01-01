// SWERC 2015 - Promotions
// Approach: DFS to find the successors of each node. Then, use this information
//           to find the number of predecessors as well. O(P*N + N^2)
//           This version uses bitwise operations to speed up merging children lists.
// Author: Miguel Oliveira
#include <cstdio>
#include <cstring>
const int MAX = 5002;
int adj[MAX][MAX], nedges[MAX], npred[MAX], N, A, B, nchildren[MAX];
char done[MAX];

typedef long long Type;
const int NBITS = sizeof(Type) * 8;
int npos;
Type is_child[MAX][MAX/NBITS + 2];
#define TWO(i) (1LL << (i))
#define SET(v, pos) v[pos/NBITS] |= TWO(pos % NBITS)
#define CONTAINS(m, i) (m & TWO(i))

void Go(int i) {
  done[i] = 1;
  for (int j = 0; j < nedges[i]; ++j) {
    int w = adj[i][j];
    if (!done[w])
      Go(w);
    SET(is_child[i], w);
    for (int k = 0; k <= npos; ++k)
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
  npos = N / NBITS + 1;
  int mustA = 0, mustB = 0, cant = 0;
  for (i = 0; i < N; ++i) 
    if (!done[i])
      Go(i);
  for (i = 0; i < N; ++i)
    for (j = 0; j <= npos; ++j) {
      nchildren[i] += __builtin_popcountll(is_child[i][j]);
      for (int k = 0; k < NBITS; ++k)
        if (CONTAINS(is_child[i][j], k)) {
            npred[j*NBITS + k]++;
        }
    }
  for (i = 0; i < N; ++i) {
    mustA += A >= (N - nchildren[i]);
    mustB += B >= (N - nchildren[i]);
    cant += npred[i] >= B;
  }
  printf("%d\n%d\n%d\n", mustA, mustB, cant);
  return 0;
}
