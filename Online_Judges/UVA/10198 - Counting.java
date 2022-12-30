import java.math.BigInteger; 
import java.util.Scanner; 

class Main{
    static int n,i;
    static BigInteger[] arr=new BigInteger[1010];
    
    public static BigInteger f(int num){
        if(num>n){
            return BigInteger.valueOf(0);
        }
        if(num==n){
            return BigInteger.valueOf(1);
        }
        if(arr[num]!=BigInteger.valueOf(0)){
            return arr[num];
        }
        BigInteger resultado = f(num+1);
        resultado=resultado.add(f(num+1));
        resultado=resultado.add(f(num+2));
        resultado=resultado.add(f(num+3));
        return arr[num]=resultado;
    }

     public static void main(String []args){
      Scanner sc = new Scanner(System.in);
    
    while(sc.hasNext()){
        n=sc.nextInt();
        
        for(i=1;i<n;++i){
            arr[i]=BigInteger.valueOf(0);
        }
        BigInteger resultado = f(1);
        resultado=resultado.add(f(1));
        resultado=resultado.add(f(2));
        resultado=resultado.add(f(3));
        System.out.println(resultado);
    }
    
     }
}