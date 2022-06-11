# README
This repository contains everything about my Competitive Programming journey. It contains solutions of contests, notebooks and solutions to problems of private online judges.

The crown jewel is the implementation of all kinds of algorithms, from the basic ones to the most complex I could understand.

You can contact me via email ([juncodelasheras@outlook.com](mailto:juncodelasheras@outlook.com)) or via Linkedin ([here](https://www.linkedin.com/in/junco-de-las-heras-valenzuela/)).

## Content:
- Contests
  > Here is the code of onsite - local contests, some of them also have the pdf of the problems.
  The most important are: Ada Byron, SWERC, Google Code Jam, Facebook Hacker Cup, Las 12 uvas.
- Implementations
  > My implementation of all kinds of algorithms, ready to copy-paste them for a contest!
  - ad_hoc (creative solutions for specific problems, not general problems, 2 SAT, clock, ternary search).
  - Bitmask (0's, 1's, binary, logic operations).
  - DataStructures (AVL, UFDS, Heap, LiChaoTree, RedBlackTree, SkipList, SplayTree, Treap, WaveletTree).
  - DP (Dynamic Programming, Kadane, LCS, LIS, Knapsack).
  - Environment (IO, Chronometer, Bash, makefile, template).
  - Geometry (Euclidean Plane, Point, Line).
  - Graphs (Articulation Points, Distances, flows, trees, DAG, cycles).
  - Hash (Custom objects hash, Pair, Set, String, Vector).
  - Math (Primes, congruences, FFT, gcd, Lagrange, Matrix).
  - Random (Random algorithms, they work < 100% of the time).
  - RangeQuery (Data Structures for Range Query, BIT, Segment Tree, Sparse Table, Square Root).
  - Strings (Strings, automatas, KMP, Rope, Trie).

- Notebook
  > Past notebooks for onsite contests (SWERC, Ada Byron).
- Online_Judges
  > Code solutions of private judges (AceptaElReto, Kattis, SPOJ, UVA-Online Judge).
  
  
- Ideas for solving a hard problem
  > If you do not have an idea of the sketch of a solution, think about how each of these ideas can solve a part of your problem.
  - Complexity O(n^2), O(n), O(log n), O(n sqrt(n)), O(n!), O(2^n).
  - Greedy.
  - Two pointers.
  - Bit masks, bitsets, iterate, there are few bits < 30 in an int.
  - Data Structure, Binary tree.
  - DP, write transitions in a paper, optimize them. Top-Down, Botom-Up, min ans, sum all possible ans, 0-1 possible ans.
  - Contribution to the answer.
  - Geometry, write auxiliary functions, binary search point in a plane with a convex function.
  - Graph, Minimum distance, flow, tree.
  - Hash a DataStructure.
  - Math well known formulas, factorize, gcd, modulus.
  - Random solution.
  - Square Root decomposition O(n sqrt(n)). 
  - String, Automaton, Rope, Trie.
  > Less general ideas.
  - Observation, Create lemmas.
  - Get invariants.
  - If you have to print a board of size n, maybe you can create a board of size 4 and replicate the pattern.
  - Maybe the solution is always <= 2, so there are few cases. Maybe sol is n, n+1 only.
  - Binary search convex functions.
  - Rotate Manhattan plane: Having a set of (i', j'), abs(i - i') + (j - j') <= k <=> max(abs(i - j - (i' - j')), abs(i + j - (i' + j'))) <= k, so only keep mx and mn of i'-j' and i'+j'.
  - Working with segments in an array, use prefixes (+ o ^).
  - Check base hardcoded cases.
  - min sum(abs(ai - x)) la mediana, min sum(abs(ai - x)^2) la media.
  - Find ways to tile all board with the same shapes (triangles, rhombus) to make DP.
  - Transform the math formula of the problem to one more symmetric: r - l = a[r] - a[l] <=> r - a[r] = l - a[l].
  - Extreme cases n = 0, n = 1, n = MAX, n = MAX-1.
  - Check epsilon, min eps = 1e-308.

