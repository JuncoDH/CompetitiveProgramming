import java.io.*;

@SuppressWarnings("unused")
public class Main {
    private final static int MAX = 100_005;

    public static void solve() {

    }


    public static void main(String... args) {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new MyScanner();
        int zz = 1;//sc.nextInt();
        while (zz-- > 0) solve();
        out.close();
    }


    private static PrintWriter out;
    private static MyScanner sc;
    private static class MyScanner {
        private static final int BUF_SIZE = 2048;
        BufferedReader br;
        private MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        private boolean isSpace(char c) {
            return c == '\n' || c == '\r' || c == ' ';
        }
        String next() {
            try {
                StringBuilder sb = new StringBuilder();
                int r;
                while ((r = br.read()) != -1 && isSpace((char) r));
                if (r == -1) {
                    return null;
                }
                sb.append((char) r);
                while ((r = br.read()) != -1 && !isSpace((char) r)) {
                    sb.append((char) r);
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}

