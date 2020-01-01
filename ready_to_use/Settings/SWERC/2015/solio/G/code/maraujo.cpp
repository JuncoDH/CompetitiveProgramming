// SWERC 2015 - Game of Cards
// Approach: Grundy Numbers
// Author: Miguel Araujo

#include <cstdio>
#include <set>
#include <vector>

#define MAXN 105
#define MAXC 1005

using namespace std;

int n, k;

int np[MAXN];

int cards[MAXN][MAXC], grundies[MAXN][MAXC];


int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &np[i]);
    for (int j = 1; j <= np[i]; j++) 
      scanf("%d", &cards[i][j]);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= np[i]; j++) {
      set<int> s;
      for (int l = 0; l <= k; l++) {
	if (j-l > 0 && j-l-cards[i][j-l] >= 0) {
	  if (j-l-cards[i][j-l] > 0)
	    s.insert(grundies[i][j-l-cards[i][j-l]]);
	  else
	    s.insert(0);
	}
      }
      int ret = 0;
      while (s.find(ret) != s.end()) ret++;
      //printf("%d ", ret);
      grundies[i][j] = ret;
    }
    //printf("%d\n", grundies[i][np[i]]);
    res = res xor grundies[i][np[i]];
  }

  //printf("Final res = %d\n", res);

  if (res == 0) puts("Bob will win.");
  else puts("Alice can win.");

  return 0;
}
