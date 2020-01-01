// SWERC 2015 - Wooden Signs
// Approach: Dynamic Programming, O(N^2) time and O(N^2) space. 
// Author: Miguel Oliveira
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2002, MOD = 2147483647;
int n, pos[MAX];
unsigned int dp[MAX][MAX];

unsigned int Solve(int cur, int last_pos) {
  if (cur > n)
    return 1;
  if (dp[cur][last_pos] == 0) {
    // Last sign is between pos[cur-1] and last_pos
    int left = min(pos[cur-1], last_pos), right = max(pos[cur-1], last_pos);
    if (pos[cur] > left) {
      dp[cur][last_pos] += Solve(cur+1, left);
      if (dp[cur][last_pos] >= MOD)
        dp[cur][last_pos] -= MOD;
    }
    if (pos[cur] < right) {
      dp[cur][last_pos] += Solve(cur+1, right);
      if (dp[cur][last_pos] >= MOD)
        dp[cur][last_pos] -= MOD;
    }
  }
  return dp[cur][last_pos];
}

int main() {
  cin >> n;
  for (int i = 0; i <= n; ++i)
    cin >> pos[i];
  cout << Solve(2, pos[0]) << endl;
  return 0;
}
