import java.io.*;
import java.math.*;

@SuppressWarnings("unused")
public class Main {
    private final static int MAX = 100_005;

    public static void solve() {
    	while(true) {
    		int n = sc.nextInt();
    		if(n == 0) return;
    		int m = sc.nextInt();
    		BigDecimal sum = new BigDecimal(1);
    		sum = sum.setScale(m, RoundingMode.FLOOR);
    		BigDecimal one = new BigDecimal(1);
    		sum = sum.setScale(m, RoundingMode.FLOOR);
    		
    		for(int i = 2; i <= n; i++) {
    			BigDecimal denom = new BigDecimal(2*i-1);
    			denom.setScale(m, RoundingMode.FLOOR);
    			if(i % 2 == 1) sum = sum.add(one.divide(denom, m, RoundingMode.FLOOR));
    			else sum = sum.add(one.divide(denom, m, RoundingMode.FLOOR).negate());
    		}
    		if(sum.toString().equals("1")) {out.print("1.\n"); continue;}
    		out.print(sum + "\n");
    	}
    }


    public static void main(String[] args) {
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
