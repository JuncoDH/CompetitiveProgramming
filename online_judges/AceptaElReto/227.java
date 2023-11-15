import java.math.BigInteger;
import java.io.*;
import java.util.*;
import java.lang.*;

public class MyClass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n,k,i;
        BigInteger num;
        
        while(true){
        n= sc.nextInt();
        k= sc.nextInt();
        
        if(n==0&&k==0){
            System.exit(0);
        }

        
        num = BigInteger.valueOf(1);
        for(i=1;i<=k;++i){
            System.out.print(num.mod(BigInteger.valueOf(1000000007)));
            System.out.print(" ");


            num=num.multiply(BigInteger.valueOf(n-i+1));
            num=num.divide(BigInteger.valueOf(i));
        }
        System.out.println(num.mod(BigInteger.valueOf(1000000007)));
        
            
        }
    }
}