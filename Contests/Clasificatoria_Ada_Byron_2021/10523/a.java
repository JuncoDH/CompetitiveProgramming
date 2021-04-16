import java.math.BigInteger;
import java.util.Scanner;
class Main{

    public static void main(String[]args){
        Scanner n = new Scanner(System.in);
        while(n.hasNextInt()){
            int n1 = n.nextInt();
            int n2 = n.nextInt();
            BigInteger ba = BigInteger.valueOf(n2);
            BigInteger ans = BigInteger.valueOf(0);
            for( int i=1;i<=n1;++i){
                BigInteger bi = BigInteger.valueOf(i);
                BigInteger b2 = ba.pow(i);
                ans=ans.add(bi.multiply(b2));
            }
            System.out.println(ans);
        }
        n.close();
    } 
}