/*AC*/

/*package javaapplication1;*/
import java.util.Scanner;
import java.math.BigInteger;


class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n, a, i;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            a = sc.nextInt();
            BigInteger sum = BigInteger.valueOf(0);
            BigInteger aa = BigInteger.valueOf(a);
            BigInteger ap = BigInteger.valueOf(a);
            for(i = 1; i <= n; i++) {
                BigInteger ii = BigInteger.valueOf(i);
                sum = sum.add(ii.multiply(ap));
                ap = ap.multiply(aa);
            }
            System.out.println(sum);
        }
    }
    
}
