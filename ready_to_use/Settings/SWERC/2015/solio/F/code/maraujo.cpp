// SWERC 2015 - Landscaping
// Approach: Maximum Flow
// Author: Miguel Araujo

#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 50*50*2
#define MAXL 52

using namespace std;

int n;
int cap[MAXN][MAXN];
int nedge[MAXN];
int edge[MAXN][MAXN];
int prev[MAXN];

void addEdge(int a, int b, int c) {
  edge[a][nedge[a]++] = b;
  cap[a][b] = c;
  /*  edge[b][nedge[b]] = a;
  cap[b][nedge[b]++] = c;*/
}

int maxFlowDinic(int s, int t) {
  int q[MAXN];
  int prev[MAXN];
  int flow = 0;
  int qf, qb, bot, u, v;
 
  while (true) {
    qf = qb = 0;
    memset(prev, -1, sizeof(prev));

    q[qb++] = s;
    prev[s] = -2;

    while (qb > qf && prev[t] == -1) {
      u = q[qf++];
      for (int i = 0; i < nedge[u]; i++)
	if (prev[v = edge[u][i]] == -1 && cap[u][v]) 
	  prev[q[qb++] = v] = u;
    }      

    if (prev[t] == -1) return flow;

    for (int z = 0; z < n; z++)
      if (cap[z][t] && prev[z] != -1) {
	bot = cap[z][t];

	for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v]) 
	  bot = min(bot , cap[u][v]);
	
	if (!bot) continue;
	cap[z][t] -= bot; 
	cap[t][z] += bot;

	for (v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
	  cap[u][v] -= bot , cap[v][u] += bot;
	flow += bot;
      }
  }
}

int linearize(int w, int i, int j) {
  return i*w+j+1;
}

int main() {
  int h, w, a, b;
  char m[MAXL][MAXL+5];

  scanf("%d %d %d %d", &h, &w, &a, &b);
  for (int i = 0; i < h; i++)
    scanf("%s", m[i]);

  n = h*w+2;

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      int act = linearize(w, i, j);
      if (m[i][j] == '.') 
        addEdge(0, act, b);
      else
        addEdge(act, n-1, b);

      if (i > 0) addEdge(act, linearize(w, i-1, j), a);
      if (i < h-1) addEdge(act, linearize(w, i+1, j), a);
      if (j > 0) addEdge(act, linearize(w, i, j-1), a);
      if (j < w-1) addEdge(act, linearize(w, i, j+1), a);
    }

  printf("%d\n", maxFlowDinic(0, n-1));

  return 0;
}
