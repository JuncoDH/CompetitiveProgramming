import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

import java.util.List;
import java.util.LinkedList;
import java.util.Deque;
import java.util.ArrayDeque;

/**
 * @author Margarida Mamede
 */


public class PromBF  // Brute Force
{

    private int nNodes;

    private List<Integer>[] inEdges; 
                                              
    private List<Integer>[] outEdges; 
                                              
    private int[] nSucs; 

    private int[] nPreds; 


    @SuppressWarnings("unchecked")
    public PromBF( int numNodes )
    {
        nNodes = numNodes;
        inEdges = (List<Integer>[]) new List[nNodes];
        outEdges = (List<Integer>[]) new List[nNodes];
        for ( int i = 0; i < nNodes; i++ )
        {
            inEdges[i] = new LinkedList<Integer>();
            outEdges[i] = new LinkedList<Integer>();
        }
        nSucs = new int[nNodes];
        nPreds = new int[nNodes];
    }


    public void addEdge( int tail, int head )
    {
        inEdges[head].add(tail);
        outEdges[tail].add(head);
    }
        

    private void compNumsPredSuc( )
    {
        Deque<Integer> waiting = new ArrayDeque<Integer>(nNodes);
        for ( int i = 0; i < nNodes; i++ )
        {
            nSucs[i] = this.bfs(outEdges, waiting, i);
            nPreds[i] = this.bfs(inEdges, waiting, i);
        }
    }


    private int bfs( List<Integer>[] edges, Deque<Integer> waiting, int root )
    {
        boolean[] found = new boolean[nNodes];

        waiting.addLast(root);
        found[root] = true;
        int numFound = 1;

        do  
            {
                int v = waiting.removeFirst();
                for ( int w : edges[v] )
                    if ( !found[w] )
                    {
                        waiting.addLast(w);
                        found[w] = true;
                        numFound++;
                    }
            }
        while ( !waiting.isEmpty() );

        return numFound;
    }


    // Node v is guaranteed to be promoted at value iff
    //   nodes - ( nSucs[v] - 1 ) <= value, that is,
    //   nodes - nSucs[v] < value.
    //
    // Node v has no possibility of being promoted at value iff
    //   value < nPreds[v].
    //
    public int[] compAnswer( int minValue, int maxValue )
    {
        this.compNumsPredSuc();

        int promsAtMin = 0;
        int promsAtMax = 0;
        int notPromoted = 0;

        for ( int i = 0; i < nNodes; i++ )
        {
            int pos = nNodes - nSucs[i];
            if ( pos < minValue )
                promsAtMin++;
            else if ( pos < maxValue )
                promsAtMax++;
            else if ( maxValue < nPreds[i] )
                notPromoted++;
        }
        promsAtMax += promsAtMin;

        return new int[] { promsAtMin, promsAtMax, notPromoted };
    }


    public static void main( String[] args ) throws IOException
    {
        BufferedReader input = 
            new BufferedReader( new InputStreamReader(System.in) );

        String[] tokens = input.readLine().split(" ");
        int minProms = Integer.parseInt( tokens[0] );
        int maxProms = Integer.parseInt( tokens[1] );
        int numNodes = Integer.parseInt( tokens[2] );
        int numEdges = Integer.parseInt( tokens[3] );

        PromBF dag = new PromBF(numNodes);
        for ( int i = 0; i < numEdges; i++ )
        {
            tokens = input.readLine().split(" ");
            int v = Integer.parseInt( tokens[0] );
            int w = Integer.parseInt( tokens[1] );
            dag.addEdge(v, w);
        }
        input.close();

        int[] answer =  dag.compAnswer(minProms, maxProms);
        System.out.println(answer[0]);
        System.out.println(answer[1]);
        System.out.println(answer[2]);
    }


}

