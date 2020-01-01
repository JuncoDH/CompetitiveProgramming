/*
 * BlackVienna solution 
 * check XOR system satifiability using Gaussian elimination
 * Pedro Vasconcelos <pbv@dcc.fc.up.pt>
 */

import java.util.*;

public class BlackVienna {
    static final int NUM_SUSPECTS= 26;

    static Constr[] constraints;    // cardinality constraints
    static int[][] coeffs;          // SAT system coefficientes
    static int rows;                // number of rows

    static final int NUM_COLS = 1 + 2*NUM_SUSPECTS;

    /* Cardinality constraints 
     */
    private static class Constr {
	public int suspect1;
	public int suspect2;
	public int player;
	public int count;
    
	public Constr(String str, int player, int count) {
	    if (str.length() != 2 
		|| player < 0 || player > 1 
		|| count< 0 || count>2 ) 
		throw new IllegalArgumentException();
	    this.suspect1 = (int)str.charAt(0) - (int)'A';
	    this.suspect2 = (int)str.charAt(1) - (int)'A';
	    this.player = player;
	    this.count = count;
	}
    }

    static int varix(int x, int p) {
	return 2*x + p;
    }

    static void addRow(int i, int c) {
	coeffs[rows][i] = 1;
	coeffs[rows][NUM_COLS-1] = c;
	rows ++;
    }
    
    static void addRow(int i, int j, int c) {
	coeffs[rows][i] = 1;
	coeffs[rows][j] = 1;
	coeffs[rows][NUM_COLS-1] = c;
	rows ++;
    }

    static void makeSystem(int bv1, int bv2, int bv3) {
	// initialize
	coeffs = new int[2*(NUM_SUSPECTS + constraints.length)][NUM_COLS];
	rows = 0;
	// suspect rows
	for (int x=0; x<NUM_SUSPECTS; x++) {
	    if (x==bv1 || x==bv2 || x==bv3) {
		addRow(varix(x,0), 0);
		addRow(varix(x,1), 0);
	    } else {
		addRow(varix(x,0), varix(x,1), 1);
	    }
	}
	// cardinality constraints
	for (int i = 0; i<constraints.length; i++) {
	    Constr c = constraints[i];
	    int x1 = c.suspect1;
	    int x2 = c.suspect2;
	    int p = c.player;
	    switch(c.count) {
	    case 0: 
		addRow(varix(x1,p), 0);
		addRow(varix(x2,p), 0);
		break;
	    case 2:
		addRow(varix(x1,p), 1);
		addRow(varix(x2,p), 1);
		break;
	    case 1:
		addRow(varix(x1,p), varix(x2,p), 1);
		break;
	    default:
		throw new IllegalArgumentException();
	    }
	}
    }

    static boolean satisfiable() {
	int i=0, j=0;
	while (i<rows && j<NUM_COLS-1) {  // until last row or before-last column
	    // find the pivot row
	    int pivot = i;
	    while (pivot < rows && coeffs[pivot][j] == 0)
		pivot++;
	    // found it?
	    if (pivot < rows) {
		int[] tmp = coeffs[pivot];  // swap rows
		coeffs[pivot] = coeffs[i];
		coeffs[i] = tmp;
	    } else {
		j++;  // advance one column and continue
		continue;
	    }

	    // here row i is the pivot row
	    // eliminate coefficients
	    for(int k=i+1; k<rows; k++) {
		if (coeffs[k][j] > 0)
		    xorRows(i, k, j);
	    }
	    // advance column and row
	    j++;
	    i++;
	}

	// Check satisfiability of row eschelon form
	int count10 = 0, count11 = 0;
	for(int k=i; k<rows; k++) {
	    if (impossible(k))
		return false; // not satisfiable
	    if(coeffs[k][NUM_COLS-2] == 1 && coeffs[j][NUM_COLS-1] == 0)
		count10 ++;
	    if(coeffs[k][NUM_COLS-2] == 1 && coeffs[j][NUM_COLS-1] == 1)
		count11 ++;		
	}
	return !(count10>0 && count11>0);
    }

    static boolean impossible(int i) {
	for (int j=0; j<NUM_COLS-1; j++)
	    if (coeffs[i][j] != 0)
		return false;
	// all coeffs are zero; if afine term is 1 then row is impossible
	return coeffs[i][NUM_COLS-1] == 1;
    }

    
    static void xorRows(int i, int k, int j) {
	while(j < NUM_COLS) {
	    coeffs[k][j] ^= coeffs[i][j];
	    j++;
	}
    }

    static int solve() {
	int solutions = 0;
	for (int x = 0; x<NUM_SUSPECTS; x++) 
	    for (int y=x+1; y<NUM_SUSPECTS; y++)
		for (int z=y+1; z<NUM_SUSPECTS; z++) {
		    makeSystem(x,y,z);
		    if(satisfiable())
			solutions ++;
		}
	return solutions;
    }

    static void readInput() {
	Scanner sc = new Scanner(System.in);
	int i, n;

	n = sc.nextInt();
	constraints = new Constr[n];
	for(i =0; i<n; i++) {
	    String str = sc.next();
	    int player = sc.nextInt() - 1;  // 0 , 1
	    int count = sc.nextInt();
	    constraints[i] = new Constr(str,player,count);
	}
    }

    public static void main(String[] args) {
	readInput();
	System.out.println(solve());
    }
}

