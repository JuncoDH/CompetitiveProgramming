import java.math.BigInteger;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s;
        while(sc.hasNext()) {
            s = sc.next();
            if(s.equals("0")) {
                System.out.println("1");
                continue;
            }
            BigInteger ans = new BigInteger("2");
            BigInteger n = new BigInteger(s);
            BigInteger n1 = n.add(new BigInteger("-1"));
            ans = ans.add(n.multiply(n1));
            System.out.println(ans);
        }
    }
}
