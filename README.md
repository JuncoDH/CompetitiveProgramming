# README
Welcome to my Competitive Programming Repository!

This repository encapsulates my entire journey in Competitive Programming. It contains solutions to various contests, notebooks, and problem-solving solutions from private online judges.

The highlight of this collection is the comprehensive implementation of a wide range of algorithms, ranging from the fundamental to the most challenging ones I found.

The code is optimized for competitive environments, prioritizing brevity and speed. As such, you won't find extensive use of unique pointers, numerous new lines to separate sentences, descriptive variable names, or a lot of comments. Despite this, I have made an effort to use a clean, maintainable and aesthetically coding style.

You can contact me via email ([juncodelasheras@outlook.com](mailto:juncodelasheras@outlook.com)) or via Linkedin ([here](https://www.linkedin.com/in/junco-de-las-heras-valenzuela/)).

## Content:
- Contests
  > Explore code of onsite and local contests, some of them have the pdf of the problems. Featured contests include:
  - **SWERC** (Southwestern Europe Regional Contest)
  - **Facebook** Hacker Cup
  - **Google Code Jam**
  - **Ada Byron**
  - **Las 12 uvas**

- Private Judges
  > Discover solutions that can not be seen publicly because the judges have not implemented a way:
  
  -  **AceptaElReto**:
    https://www.aceptaelreto.com/

  -  **Kattis**:
    https://open.kattis.com/

  -  **SPOJ**:
    https://www.spoj.com/

  -  **UVA**, **Online Judge**:
    https://onlinejudge.org/
    (old: https://uva.onlinejudge.org/)

- Implementations
  > Access my comprehensive implementations of all kinds of algorithms, ready for copy-pasting in competitions!

  - **ad_hoc**: Creative solutions for specific problems, 2 sat, clock, ternary search, vector.
  - **bitmask**: Handling 0's, 1's, binary, logic operations, operations, inclusion exclusion.
  - **data_structures**: avl, ufds, heaps, li chao tree, red black tree, skip list, splay tree, treap, wavelet tree.
  - **dp**: dynamic programming, kadane, lcs, lis, knapsack, digit dp.
  - **environment**: personal setup, io, chronometer, bash, makefile, template, pragmas.
  - **geometry**: euclidean plane, point, line, intersection, triangles, areas.
  - **graphs**: articulation points, distances, flows, trees, dag, cycles, decompositions, strongly connected component, minimum spanning trees, lowest common ancestors.
  - **hash**: custom objects hash, number, pair, set, string, vector, queue.
  - **math**: primes, congruences, fft, gcd, lagrange interpolation, matrix, formulas, gcd, combinatorial numbers.
  - **random**: random algorithms, they work <= 100% of the time, maximum independent set in a graph, random numbers.
  - **range query**: data structures for range query, bit fenwick, segment tree, sparse table, square root decomposition, mo.
  - **strings**: strings, automatas, aho corasick, kmp, rope, trie, palindromes, suffix array, z algorithm.

- Notebook
  > Access past notebooks from onsite contests SWERC and Ada Byron.

- Ideas for solving a hard problem
  > If you do not have an idea of how to tackle a problem, think about how each of these ideas can solve a part of your problem, and then try to combine them to form your solution.
  - Complexity O(n^2), O(n), O(log n), O(n sqrt(n)), O(n!), O(2^n).
  - Simulation.
  - Greedy.
  - Binary Search.
  - Sort.
  - Two pointers.
  - Bit masks, bitsets, iterate, there are few bits < 30 in an int.
  - Data Structure, Binary tree.
  - DP, write transitions in a paper, optimize them. Top-Down, Botom-Up, min ans, sum all possible ans, 0-1 possible ans.
  - Contribution to the answer.
  - Branch and bound.
  - Brute force.
  - Geometry, write auxiliary functions, binary search point in a plane with a convex function.
  - Graph, Minimum distance, flow, tree.
  - Split graph into SCC.
  - Hash a DataStructure.
  - Math well known formulas, factorize, gcd, modulus.
  - Random solution.
  - Square Root decomposition O(n sqrt(n)). 
  - String, Automaton, Rope, Trie.
  > More uncommon ideas.
  - Observation, Create lemmas.
  - Get invariants: Parity, Sum a[i]
  - If you have to print a board of size n, maybe you can create a board of size 4 and replicate the pattern.
  - Maybe the solution is always <= 2, so there are few cases. Maybe sol is n, n+1 only.
  - Binary search convex functions.
  - Rotate Manhattan plane: Having a set of (i', j'), abs(i - i') + (j - j') <= k <=> max(abs(i - j - (i' - j')), abs(i + j - (i' + j'))) <= k, so only keep mx and mn of i' - j' and i' + j'.
  - Working with segments in an array, use prefixes (+ o ^).
  - Check base hardcoded cases.
  - min sum(abs(a_i - x)) the median, min sum(abs(a_i - x)^2) the mean.
  - Find ways to tile all board with the same shapes (triangles, rhombus) to make DP.
  - Transform the math formula of the problem to one more symmetric: r - l = a[r] - a[l] <=> r - a[r] = l - a[l].
  - Extreme cases n < 0, n = 0, n = 1, n = MAX, n = MAX - 1.
  - Check epsilon, min eps = 1e-308.
  - Create graph from points, there is an edge i->j if f(i, j) satisfies a given property.
  - When creating palindromes, usually is 111...111 or 99...99.
  - If the greedy doesn't work, its because a step in your proof is WRONG.
  - If you have 3 operations, maybe one can do all in the beginning, or in the end.
  - Take derivative array. v'[i] = v[i] - v[i - 1].
  - If have to check if is possible to convert a to c, maybe check a middle state a to b and c to b, special if the operations are reversible.
  - Use WolframAlpha to simplify: 'sum b + i choose i, i = 0 to a'.
  - Maybe the problem has wrong limits.
  - Maybe there is more than one test case.
  - The test case doesn't finish in 0 0 if not said otherwise.
  - Birthday paradox: In a set of n elements, the first match will be in sqrt(n). With 2^n, will be 2^(n / 2). In a set of n elements, will be O(n) ~ n / 3 elements that are repeated.
  - Sweep line, left to right.
  - When removing an element from the solution, double check that it can't be the answer.
  - Usually you have to consume all the queries in interactive problems. 
  - Try to convert the arrays to 0-index.
  - Maybe instead of giving ans, give total - not ans.
  - lcm(i, j, k) = k, 2k, it will be only few cases.
  - Maybe to create a graph from a vector the edges are local j - i < 400.
  - Use lambdas with repeated blocks.
  - Use sqrtl and powl to return long double.
  - multiset.erase(num) erase all repetitions. erase(ms.find()) only one.
  - Check that you are running the correct test case.
  - Sometimes you can create a solution just defining a[i][j] := i * j;
  - N queen problem always has a solution for N > 3.
  - Euler formula in a planar graph v + f = e + 2, count the total space.
  - Handshaking lemma sum of degree = 2 * e.
  - Reflect the pool table, or the ant collision.
  - Maybe you think that your function f is not increasing, but it is strictly decreasing and you need that for ternary search. 
  
