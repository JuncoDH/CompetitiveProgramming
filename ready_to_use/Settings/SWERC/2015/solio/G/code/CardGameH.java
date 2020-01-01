// SWERC 2015 - Game of Cards
// Approach: Grundy Numbers
// Author: Margarida Mamede

import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

import java.util.Set;
import java.util.HashSet;

/**
 * @author Margarida Mamede
 */


public class CardGameH // HashSet
{

    private static int pileNimber( int[] cards, int maxRem )
    {
        int[] nimbers = new int[cards.length];
        int setMaxSize = maxRem + 1;

        for ( int c = 1; c < cards.length; c++ )
        {
            Set<Integer> set = new HashSet<Integer>(setMaxSize);
            for ( int r = 0; r <= maxRem && r < c; r++ )
            {
                int pos = c - r - cards[c - r];
                if ( pos >= 0 )
                    set.add( nimbers[pos] );
            }
            nimbers[c] = minNatMissing(set);
        }
        return nimbers[cards.length - 1];
    }


    private static int minNatMissing( Set<Integer> set )
    {
        int number = 0;
        while ( set.contains(number) )
            number++;
        return number;
    }


    public static void main( String[] args ) throws IOException
    {
        BufferedReader input = 
            new BufferedReader( new InputStreamReader(System.in) );

        String[] tokens = input.readLine().split(" ");
        int piles = Integer.parseInt( tokens[0] );
        int maxRem = Integer.parseInt( tokens[1] );

        int state = 0;

        for ( int p = 0; p < piles; p++ )
        {
            tokens = input.readLine().split(" ");
            int[] cards = new int[tokens.length];

            for ( int i = 1; i < tokens.length; i++ )
                cards[i] = Integer.parseInt( tokens[i] );
                
            state = state ^ pileNimber(cards, maxRem);
        }
        input.close();

        if ( state == 0 )
            System.out.println("Bob will win.");
        else
            System.out.println("Alice can win.");
    }


}

