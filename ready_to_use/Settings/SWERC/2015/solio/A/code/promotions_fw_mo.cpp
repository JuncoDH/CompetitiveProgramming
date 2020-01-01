// SWERC 2015 - Promotions
// Approach: Floyd-Warshall to find the transitive closure, using bitwise operations.
//           O(N^3) but bitwise operations + flag -O2 are a killer.
// Author: Miguel Oliveira
#include <cstdio>
#define INDEX(i, j)       i * NBITS + j
#define CONTAINS(m, i)    (m & TWO(i))
#define TWO(i)            (1LL << (i))
#define SET(v, pos)       v[pos/NBITS] |= TWO(pos % NBITS)
const int NBITS = sizeof(long long) * 8;
const int MAX = 5000 + 2 * NBITS;
int npred[MAX], nchildren[MAX], npos, N;
long long is_child[MAX][MAX/NBITS + 2];

// Floyd-Warshall algorithm to find the transitive closure of each vertex.
void TransitiveClosure() {
  for (int k = 0; k < N; ++k) {
    int pos = k / NBITS, bit = k % NBITS;
    for (int p = 0; p <= npos; ++p) 
      for (int i = 0; i < NBITS; ++i) 
        if (CONTAINS(is_child[INDEX(p, i)][pos], bit)) 
          for (int j = 0; j <= npos; ++j) 
            is_child[INDEX(p, i)][j] |= is_child[k][j];
  }
}
void CountSucPred() {  // Find the number of successors and predecessors.
  for (int i = 0; i < N; ++i)
    for (int j = 0; j <= npos; ++j) {
      nchildren[i] += __builtin_popcountll(is_child[i][j]);
      for (int k = 0; k < NBITS; ++k)
        if (CONTAINS(is_child[i][j], k))
            ++npred[INDEX(j, k)];
    }
}

int main() {
  int i, j, A, B, P;
  scanf("%d %d %d %d", &A, &B, &N, &P);
  npos = N / NBITS + 1;
  while (P--) {
    scanf("%d %d", &i, &j);
    SET(is_child[i], j);
  }
  TransitiveClosure();
  CountSucPred();
  int mustA = 0, mustB = 0, cant = 0;
  for (i = 0; i < N; ++i) {
    mustA += A >= (N - nchildren[i]);
    mustB += B >= (N - nchildren[i]);
    cant += npred[i] >= B;
  }
  printf("%d\n%d\n%d\n", mustA, mustB, cant);
  return 0;
}
