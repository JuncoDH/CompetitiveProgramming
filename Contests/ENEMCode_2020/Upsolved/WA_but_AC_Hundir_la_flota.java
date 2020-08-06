import java.io.*;
import java.math.BigInteger;
import java.util.Date;

@SuppressWarnings("unused")
public class Main {
    private final static int MAX = 100_005;
    
    static BigInteger[] gcdEx(BigInteger p, BigInteger q) {
        if (q.equals(BigInteger.ZERO))
           return new BigInteger[] { p, BigInteger.ONE, BigInteger.ZERO };

        BigInteger[] vals = gcdEx(q, p.mod(q));
        BigInteger d = vals[0];
        BigInteger a = vals[2];
        BigInteger b = vals[1].subtract(p.divide(q).multiply(vals[2]));
        return new BigInteger[] { d, a, b };
     }
    
    /**
     * UPDATE: The test cases are wrong, confirmed by the setter of the problem.
     *
     * This gives WA but there are weird test cases...
     * 
     * 
     * The 4º test starting by the end, on the Test Case 1 is this:
     * 3488934 2753635
	 * 398061907266 8554950438938 3283643256489
	 * 
	 * e = x2 - x1;
	 * d = x1 - x0;
	 * e = a*d mod m
	 * e = a*d + m*k for some natural k
	 * 
	 * This program gives no solution since m and d are even but e is odd.
	 * 
	 * The model solution gives as answer 28449863368704.
	 */
    public static void solve() {
    	long a = sc.nextLong();
    	long b = sc.nextLong();
    	long xl0 = sc.nextLong();
    	long xl1 = sc.nextLong();
    	long xl2 = sc.nextLong();
    	
    	BigInteger x0 = BigInteger.valueOf(xl0);
    	BigInteger x1 = BigInteger.valueOf(xl1);
    	BigInteger x2 = BigInteger.valueOf(xl2);
    	
    	
    	BigInteger m = BigInteger.valueOf(a*b);
    	
    	BigInteger e = x2.subtract(x1);
    	e = e.mod(m);
    	
    	BigInteger d = x1.subtract(x0);
    	d = d.mod(m);
    	
    	BigInteger g = d.gcd(m), xx, c;
    	//out.println("e" + e);
    	//out.println("d" + d);
    	//out.println("m" + m);
    	//out.println("g" + g);
    	//out.println("equals: " + e.mod(g));
    	if(e.mod(g).equals(BigInteger.ZERO) == false) {
    		out.println("HA MENTIDO A SU DEPARTAMENTO!!");
    		return;
    	}
    	
    	BigInteger[] ans = gcdEx(d.divide(g), m.divide(g));
    	//out.println(ans[0] + " " + ans[1] + " " + ans[2]);
    	
    	xx = ans[1];
    	//out.println("minisol" + xx);
    	xx = xx.multiply(e.divide(g));
    	//out.println("minisol" + xx + " " + e + " g:" + g + " " + e.divide(g));
    	xx = xx.mod(m.divide(g));
    	
    	c = x1.subtract(xx.multiply(x0));
    	c = c.mod(m);
    	//out.println("sol" + xx + " " + c);
    	//out.println("comp:" + xx.multiply(x0).add(c).mod(m));
    	//out.println("comp:" + xx.multiply(x1).add(c).mod(m));
    	
    	if(!x1.equals(xx.multiply(x0).add(c).mod(m))) {
    		out.println("HA MENTIDO A SU DEPARTAMENTO!!");
    		return;
    	}
    	if(!x2.equals(xx.multiply(x1).add(c).mod(m))) {
    		out.println("HA MENTIDO A SU DEPARTAMENTO!!");
    		return;
    	}
		out.println(xx.multiply(x2).add(c).mod(m)); 	
    }


    public static void main(String... args) {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new MyScanner();
        int zz = sc.nextInt();
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

