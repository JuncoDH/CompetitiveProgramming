import java.util.*;
import java.lang.*;
import java.io.*;


class Main {
    
    static node[] edges;
    static int n, r;
    static int parent[], rank[];
    
    static void ini() {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    static int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    static void union(int u, int v) {
        u = find(u);
        v = find(v);
        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
    
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);

      int c1, c2, p, i, s, d, t, ans, temp, dx, tcase = 1;
      
      while(true) {
          n = sc.nextInt();
          r = sc.nextInt();
          if(n == 0 && r == 0) return;
          edges = new node[r];
          for(i = 0; i < r; ++i) {
              c1 = sc.nextInt(); c1--;
              c2 = sc.nextInt(); c2--;
              p = sc.nextInt();
              edges[i] = new node(c1, c2, p);
          }
          s = sc.nextInt(); s--;
          d = sc.nextInt(); d--;
          t = sc.nextInt();
          
          Arrays.sort(edges);

          ini();
          for(i = 0; i < r; i++) {
              union(edges[i].u, edges[i].v);
              if(find(s) == find(d)) break;
          }
          
          ans = 0;
          dx = edges[i].w;
          while(t >= dx) {
                temp = t / dx;
                ans += temp;
                t = t - temp * dx + temp;
          }
          if(t != 0) ans++;
          System.out.println("Scenario #" + tcase); tcase++;
          System.out.println("Minimum Number of Trips = " + ans);
          System.out.println("");
      }
    }
    
    static class node implements Comparable<node> {
        int u, v, w;
        node(int _u, int _v, int _w) {
            this.u = _u;
            this.v = _v;
            this.w = _w;
        }

        public int compareTo(node x) {
            return x.w - this.w;
        }
    }
}