import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

import java.util.List;
import java.util.LinkedList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.BitSet;

/**
 * @author Margarida Mamede
 */


public class PromBS  // Bit Sets
{

    private int nNodes;

    private int[] inDegree; 
                                              
    private List<Integer>[] outEdges; 
                          
    private BitSet[] preds;

    private int[] nSucs; 

    private int[] nPreds; 


    @SuppressWarnings("unchecked")
    public PromBS( int numNodes )
    {
        nNodes = numNodes;
        inDegree = new int[nNodes];
        outEdges = (List<Integer>[]) new List[nNodes];
        for ( int i = 0; i < nNodes; i++ )
            outEdges[i] = new LinkedList<Integer>();
        preds = new BitSet[nNodes];
        nSucs = new int[nNodes];
        nPreds = new int[nNodes];
    }


    public void addEdge( int tail, int head )
    {
        inDegree[head]++;
        outEdges[tail].add(head);
    }
        

    private void compNumsPredSuc( )
    {
        this.compPreds();
        for ( int i = 0; i < nNodes; i++ )
            for ( int j = 0; j < nNodes; j++ )
                if ( preds[i].get(j) )
                {
                    nPreds[i]++;
                    nSucs[j]++;
                }
    }


    private void compPreds( )
    {
        Deque<Integer> ready = new ArrayDeque<Integer>(nNodes);

        for ( int i = 0; i < nNodes; i++ )
        {
            preds[i] = new BitSet(nNodes);
            preds[i].set(i);
            if ( inDegree[i] == 0 )
                ready.addLast(i);
        }

        do  
            {
                int v = ready.removeFirst();
                for ( int w : outEdges[v] )
                {
                    preds[w].or(preds[v]);
                    inDegree[w]--;
                    if ( inDegree[w] == 0 )
                        ready.add(w);
                }
            }
        while ( !ready.isEmpty() );
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

        PromBS dag = new PromBS(numNodes);
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

