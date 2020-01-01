import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * @author Margarida Mamede
 */


public class WoodenSigns
{

    public static final long MAX_VAL = Integer.MAX_VALUE;


    private int[] perm; 

    private long[][] nSigns; 
                                              

    public WoodenSigns( int[] permutation )
    {
        perm = permutation;
        nSigns = new long[perm.length][perm.length];
    }


    public long numSigns( )
    {
        return this.numSigns(2, perm[0], perm[1]);
    }
        

    public long numSigns( int posPerm, int left, int right )
    {
        if ( nSigns[left][right] == 0 )
        {
            if ( posPerm == perm.length )
                nSigns[left][right] = 1L;
            else
            {
                int value = perm[posPerm];
                long nSignsLeft = 0L;
                if ( left < value )
                    nSignsLeft = this.numSigns(posPerm + 1, left, value);
                long nSignsRight = 0L;
                if ( value < right )
                    nSignsRight = this.numSigns(posPerm + 1, value, right);
                
                nSigns[left][right] = ( nSignsLeft + nSignsRight ) % MAX_VAL;
            }
        }
        return nSigns[left][right];
    }


    public static void main( String[] args ) throws IOException
    {
        BufferedReader input = 
            new BufferedReader( new InputStreamReader(System.in) );

        input.readLine();
        String[] tokens = input.readLine().split(" ");
        int[] permutation = new int[tokens.length];
        for ( int i = 0; i < tokens.length; i++ )
            permutation[i] = Integer.parseInt( tokens[i] ) - 1;
        input.close();

        WoodenSigns seq = new WoodenSigns(permutation);
        System.out.println(seq.numSigns());
    }


}

