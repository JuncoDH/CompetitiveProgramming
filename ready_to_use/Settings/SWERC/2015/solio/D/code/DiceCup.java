/*
 * DiceCup Naive solution
 * Compute all sums and accumulate occorrences
 * Pedro Vasconcelos <pbv@dcc.fc.up.pt>, 2015
 */

import java.util.Scanner;

public class DiceCup {
    static int hist[];         // outcome histogram
    
    static void dice(int n, int m) {
	/* compute histogram and maximum frequency */
	int maxFreq = 0;
	hist = new int[n+m+1];  // default initialization (zeros)
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=m; j++) {
		hist[i+j] ++;
		if(hist[i+j] > maxFreq)
		    maxFreq = hist[i+j];
	    }

	for (int s=2; s<=n+m; s++) {
	    if(hist[s] == maxFreq) 
		System.out.println(s);
	}
    }

    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int m = sc.nextInt();
	dice(n,m);
    }
}
