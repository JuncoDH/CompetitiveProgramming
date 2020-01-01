// SWERC 2015 - Black Vienna
// Approach: 2SAT - 1 variable per suspect + variable always false
//   If we use 2 variables per suspect (1 for each player), these pairs of 
//   variables are the complement of each other except for the spies in the
//   Black Vienna. This version uses only one variable per suspect, treating
//   Si = 0 as suspect i belonging to one player and Si = 1 as belonging to the other.
// Author: Miguel Oliveira
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
#define T(x) 2*(x)
#define F(x) 2*(x)+1
const int MAXV = 200;

struct SatInstance {
  int nvars, n, nc, root[MAXV], comp[MAXV], size[MAXV], vis[MAXV]; 
  stack<int> s;
  vector<int> adj[MAXV];

  SatInstance(int nv) : nvars(nv) { n=0; }

  void AddClause(int x, bool bx, int y, bool by ) { //vars e valor booleano na clausula 
    int hipx, hipy , tx, ty;
    if (bx)   hipx = F(x) , ty = T(x);
    else      hipx = T(x) , ty = F(x);

    if (by)   hipy = F(y) , tx = T(y);
    else      hipy = T(y) , tx = F(y);
    adj[hipx].push_back(tx); 
    adj[hipy].push_back(ty);
    n = max(n, max(hipx, hipy));
  }

  void SCC() {
    memset(vis, 0, sizeof vis);
    memset(size, 0, sizeof size);
    memset(comp, 0, sizeof comp);
    memset(root, 0, sizeof root);
    nc = 0;
    for (int i = 1; i <= n; ++i) /* Find Strong Components */ 
      if (!vis[i])
        tarjan(i, 0); 
  }
  void tarjan(int v, int d) {
    root[v] = d; vis[v]=1; s.push(v);
    for (size_t i = 0; i < adj[v].size(); ++i) {
      if (!vis[adj[v][i]]) 
        tarjan(adj[v][i], d+1);
      if (comp[adj[v][i]] == 0) 
        root[v] = min(root[v], root[adj[v][i]]); 
    }
    if (root[v] == d) { 
      comp[v] = ++nc;
      for (size[nc] = 1; s.top() != v; s.pop(), size[nc]++)
        comp[s.top()] = nc;
      s.pop();
    } 
  }
  bool IsSatisfiable() {
    SCC();
    bool ok = true;                          // Se A e ~A estiverem na mesma 
    for (int i = 1; ok && i <= nvars; ++i)   // componente, não
      ok = comp[T(i)] != comp[F(i)];         // é satisfazivel 
    return ok;
  }
};

const int MAX_SUSPECTS = 26;
const int ZERO = MAX_SUSPECTS + 1;
int answer[MAXV], player[MAXV], card[MAXV][2], N;

// See if a card is one of the spies in the Black Vienna.
inline bool Is(int i, int a, int b, int c) { return i == a || i == b || i == c; }

bool BlackViennaCheck(int a, int b, int c) {
  SatInstance instance(MAX_SUSPECTS+1);
  instance.AddClause(ZERO, false, ZERO, false);
  for (int i = 0; i < N; ++i)
    if (answer[i] == 0) {
      // (!Ai OR Z) AND (!Bi OR Z)
      if (!Is(card[i][0], a, b, c))
        instance.AddClause(card[i][0], player[i], ZERO, true);
      if (!Is(card[i][1], a, b, c))
        instance.AddClause(card[i][1], player[i], ZERO, true);
    } else if (answer[i] == 1) {
      if (Is(card[i][0], a, b, c) && Is(card[i][1], a, b, c))
        return false;
      if (Is(card[i][0], a, b, c)) {
        instance.AddClause(card[i][1], !player[i], ZERO, true);
      } else if (Is(card[i][1], a, b, c)) {
        instance.AddClause(card[i][0], !player[i], ZERO, true);
      } else {
        // (Ai OR Bi) AND (!Ai OR !Bi)
        instance.AddClause(card[i][0], !player[i], card[i][1], !player[i]);
        instance.AddClause(card[i][0], player[i], card[i][1], player[i]);
      }
    } else {
      // (Ai OR Z) AND (Bi OR Z)
      if (Is(card[i][0], a, b, c) || Is(card[i][1], a, b, c))
        return false;
      instance.AddClause(card[i][0], !player[i], ZERO, true);
      instance.AddClause(card[i][1], !player[i], ZERO, true);
    }
  return instance.IsSatisfiable();
}
int main() {
  string s;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> s >> player[i] >> answer[i];
    player[i]--;
    card[i][0] = s[0] - 'A' + 1;
    card[i][1] = s[1] - 'A' + 1;
  }
  int num_solutions = 0;
  for (int i = 1; i <= MAX_SUSPECTS; ++i)
    for (int j = i+1; j <= MAX_SUSPECTS; ++j)
      for (int k = j+1; k <= MAX_SUSPECTS; ++k)
        num_solutions += BlackViennaCheck(i, j, k);
  cout << num_solutions << endl;
  return 0;
}
