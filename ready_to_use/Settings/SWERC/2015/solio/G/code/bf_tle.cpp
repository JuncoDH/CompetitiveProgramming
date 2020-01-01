// SWERC 2015 - Game of Cards
// Approach: Brute Force
// Author: Miguel Araujo

#include <cstdio>
#include <vector>

#define MAXN 100

using namespace std;

int n, k;

int np[MAXN];

vector<int> cards[MAXN];

int status[MAXN];

bool canWin(bool alice) {
  for (int i = 0; i < n; i++) 
    for (int j = 0; j <= k && j < status[i]; j++) {
      int removal = j + cards[i][status[i]-j-1];
      if (removal <= status[i]) {
	status[i] -= removal;
	bool victory = !canWin(!alice);
	status[i] += removal;
	if (victory) return true;
      }
    }    
  return false;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &np[i]);
    int temp;
    for (int j = 0; j < np[i]; j++) {
      scanf("%d", &temp);
      cards[i].push_back(temp);
    }
    status[i] = np[i];
  }
  
  if (canWin(true)) puts("Alice can win.");
  else puts("Bob will win.");
  
  return 0;
}
