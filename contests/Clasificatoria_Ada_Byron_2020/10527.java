import java.math.BigInteger;
import java.util.*;

class Main {

    public static void main(String[] args){

        Scanner s= new Scanner(System.in);
        String a;
        int i;
        while(s.hasNext()){
            a=s.next();
            
            if(a.equals("-1")) break;
            if(a.equals("0")) {
                System.out.println("10");
                continue;
            }
            if(a.equals("1")) {
                System.out.println("11");
                continue;
            }
            if(a.length() < 2) {
                System.out.print(1);
            }

            BigInteger n = new BigInteger(a);
            int ad[]= new int[10];
            //int last = 0;
            for(i = 9; i > 1; i--) {
                while(n.mod(new BigInteger(Integer.toString(i))).equals(BigInteger.ZERO)) {
                    n = n.divide(new BigInteger(Integer.toString(i)));
                    ad[i]++;
                }
            }
            if(!n.equals(BigInteger.ONE)) {
                System.out.println("There is no such number.");
                continue;
            }
            int j;
            for(i = 2; i <= 9; i++) {
                for(j = 0; j < ad[i]; j++) {
                    System.out.print(i);
                }
            }
            System.out.println("");

        }



    }



}