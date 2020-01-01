import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

import java.util.Queue;
import java.util.PriorityQueue;

/**
 * @author Margarida Mamede
 */


public class Painting
{

    public static long minPaint( Queue<Long> seq )
    {
        int nScans = seq.size() - 1;
        long sum = 0L;

        for ( int i = 0; i < nScans; i++ )
        {
            long colorX = seq.remove();
            long colorY = seq.remove();
            long oldColor = colorX + colorY;
            seq.add(oldColor);
            sum += oldColor;
        }
        return sum;
    }


    public static void main( String[] args ) throws IOException
    {
        BufferedReader input = 
            new BufferedReader( new InputStreamReader(System.in) );

        int nTests = Integer.parseInt( input.readLine() );

        for ( int t = 0; t < nTests; t++ )
        {
            int nCanvas = Integer.parseInt( input.readLine() );
            Queue<Long> canvas = new PriorityQueue<Long>(nCanvas);

            String[] tokens = input.readLine().split(" ");
            for ( int i = 0; i < nCanvas; i++ )
                canvas.add( Long.parseLong( tokens[i] ) );

            System.out.println( minPaint(canvas) );
        }
        input.close();
    }


}

