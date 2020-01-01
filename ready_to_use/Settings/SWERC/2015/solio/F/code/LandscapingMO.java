// SWERC 2015 - Landscaping
// Approach: Maximum Flow
// Author: Miguel Oliveira
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;

public class LandscapingMO {

  public static void main( String[] args ) throws IOException {
    BufferedReader input = new BufferedReader( new InputStreamReader(System.in) );
    String[] tokens = input.readLine().split(" ");
    int L = Integer.parseInt(tokens[0]);
    int C = Integer.parseInt(tokens[1]);
    int A = Integer.parseInt(tokens[2]);
    int B = Integer.parseInt(tokens[3]);
    String[] land = new String[L];
    for (int i = 0; i < L; i++)
      land[i] = input.readLine();
    input.close();
    System.out.println(solve(L, C, A, B, land));       
  }

  public static int solve(int L, int C, int A, int B, String[] land) {
    int nvertices = L * C + 2, source = 0, sink = L*C + 1;
    int[] dx = new int[]{0, 1};
    int[] dy = new int[]{1, 0};
    Graph graph = new Graph(nvertices);
    for (int i = 0; i < L; i++)
      for (int j = 0; j < C; j++) {
        if (land[i].charAt(j) == '.')
          graph.addEdge(source, getVertex(i, j, C), B, 0);
        else
          graph.addEdge(getVertex(i, j, C), sink, B, 0);
        for (int k = 0; k < dx.length; k++) {
          int x = j + dx[k], y = i + dy[k];
          if (x >= 0 && x < C && y >= 0 && y < L)
            graph.addEdge(getVertex(i, j, C), getVertex(y, x, C), A, A);
        }
      }
    return graph.maximumFlow(source, sink);
  }

  public static int getVertex(int i, int j, int C) { return i * C + j + 1; }

  static class Graph {
    List<List<Integer>> adjacencyList;
    int[][] capacity;

    public Graph(int nvertices) {
      adjacencyList = new ArrayList<List<Integer>>();
      for (int i = 0; i < nvertices; i++)
        adjacencyList.add(new ArrayList<Integer>());
      capacity = new int[nvertices][nvertices];
    }

    public void addEdge(int from, int to, int fwdCap, int revCap) {
      adjacencyList.get(from).add(to);
      capacity[from][to] = fwdCap;
      adjacencyList.get(to).add(from);
      capacity[to][from] = revCap;
    }
    
    public int maximumFlow(int source, int sink) {
      int flow = 0, inc;
      boolean[] visited = new boolean[adjacencyList.size()];
      do {
        Arrays.fill(visited, false);
        inc = dfs(source, sink, Integer.MAX_VALUE, visited);
        flow += inc;
      } while (inc > 0);
      return flow;
    }
   
    public int dfs(int vertex, int sink, int flow, boolean[] visited) {
      if (vertex == sink)
        return flow;
      visited[vertex] = true;
      for (int next : adjacencyList.get(vertex)) {
        if (!visited[next] && capacity[vertex][next] > 0) {
          int f = dfs(next, sink, Math.min(flow, capacity[vertex][next]), visited);
          if (f > 0) {
            capacity[vertex][next] -= f;
            capacity[next][vertex] += f;
            return f;
          }
        }
      }
      return 0;
    }
  }
}
