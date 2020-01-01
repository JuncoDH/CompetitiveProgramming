// SWERC 2015 - Black Vienna 
// Approach: Reduce the problem to a 2-SAT instance
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
    for (int i = 1; i <= n; ++i) 
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
const int ZERO = 2*MAX_SUSPECTS + 1;
int answer[MAXV], player[MAXV], card[MAXV][2], N;

int Var(int player, int var) { return var + player * MAX_SUSPECTS; }

bool BlackViennaCheck(int a, int b, int c) {
  SatInstance instance(2*MAX_SUSPECTS+1);
  // Artificial variable Zero that is always false. Used below (as Z).
  instance.AddClause(ZERO, false, ZERO, false);
  for (int i = 0; i < 2; ++i) {
    // (!Ai OR Z) : the spies are not in the players hands.
    instance.AddClause(Var(i, a), false, ZERO, true);
    instance.AddClause(Var(i, b), false, ZERO, true);
    instance.AddClause(Var(i, c), false, ZERO, true);
  }
  for (int i = 1; i <= MAX_SUSPECTS; ++i)
    if (i != a && i != b && i != c) {
      // (A1 OR A2) AND (!A1 OR !A2) : The other suspects must be in one of the players hands.
      instance.AddClause(Var(0, i), true, Var(1, i), true);
      instance.AddClause(Var(0, i), false, Var(1, i), false);
    }

  for (int i = 0; i < N; ++i)
    if (answer[i] == 0) {
      // (!Ai OR Z) AND (!Bi OR Z)
      instance.AddClause(Var(player[i], card[i][0]), false, ZERO, true);
      instance.AddClause(Var(player[i], card[i][1]), false, ZERO, true);
    } else if (answer[i] == 1) {
      // (Ai OR Bi) AND (!Ai OR !Bi)
      instance.AddClause(Var(player[i], card[i][0]), true, Var(player[i], card[i][1]), true);
      instance.AddClause(Var(player[i], card[i][0]), false, Var(player[i], card[i][1]), false);
    } else {
      // (Ai OR Z) AND (Bi OR Z)
      instance.AddClause(Var(player[i], card[i][0]), true, ZERO, true);
      instance.AddClause(Var(player[i], card[i][1]), true, ZERO, true);
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
