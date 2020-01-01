/*
 * DiceCup optimal solution
 * Mmost likely outcomes are [min(n,m)+1 .. max(n,m)+1]
 * Pedro Vasconcelos <pbv@dcc.fc.up.pt>, 2015
 */

import java.util.Scanner;

public class DiceCup2 {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int m = sc.nextInt();
	
	for (int i = Math.min(n,m)+1; i<= Math.max(n,m)+1; i++) {
	    System.out.println(i);
	}
    }
}



