# CCppCodingCollection [Competitive Coding]

This Repository contains majority of the programs that I have created on my local system so far.
Most of the codes are solutions of various competitive challenges and practice problems on CodeChef, Hackerrank, Hackerearth, Codeforces and LeetCode etc.

| Platform      |                             Profile Link                              |                                                                             Codes Link |
| ------------- | :-------------------------------------------------------------------: | -------------------------------------------------------------------------------------: |
| HackerEarth   |         [Profile](https://www.hackerearth.com/@arorakartik4)          |   [Codes](https://github.com/KartikWatts/CCppCodingCollection/tree/master/HackerEarth) |
| CodeChef      |         [Profile](https://www.codechef.com/users/kartikarora)         |      [Codes](https://github.com/KartikWatts/CCppCodingCollection/tree/master/CodeChef) |
| CodeForces    |         [Profile](https://codeforces.com/profile/kartikwatts)         |    [Codes](https://github.com/KartikWatts/CCppCodingCollection/tree/master/CodeForces) |
| LeetCode      |              [Profile](https://leetcode.com/kartikwatts)              |      [Codes](https://github.com/KartikWatts/CCppCodingCollection/tree/master/LeetCode) |
| GeeksForGeeks | [Profile](https://auth.geeksforgeeks.org/user/kartik%20watts/profile) | [Codes](https://github.com/KartikWatts/CCppCodingCollection/tree/master/GeeksForGeeks) |

## VS Code Config Shortcuts

`CTRL + SHIFT + B` => BUILD THE PROGRAM TAKING INPUT FROM input.txt, AND DISPLAY OUTPUT AT output.txt, CHECKING DIFFERENCE FROM solution.txt AND CORRESPONDINGLY UPDATING difference.txt

`CTRL + SHIFT + V` => PREVIEW MARKDOWN

## SOME INTERESTING CODE SNIPPETS:

```
// Directly take input in a Vector of size n:
VI v(n);
for (int &i : v)
    cin >> i;
```

```
// Sort Vector in Descending order:
sort(all(v), greater<int>());
```

```
// Loop through elements of Vector
for(auto el: v)
cout<<el;
```

## NOTES:

### From Competitive Programming 3 - Steven Halim, Felix Halim

-   #### Tips to be Competitive

    -   Tip 1: Type Code Faster!
    -   Tip 2: Quickly Identify Problem Types
    -   Tip 3: Do Algorithm Analysis
    -   Tip 4: Master Programming Languages
    -   Tip 5: Master the Art of Testing Code
    -   Tip 6: Practice and More Practice

-   Modern computers are quite fast and can process 5 up to ≈ 100M (or 108 ; 1M = 1, 000, 000)
    operations in a few seconds. You can use this information to determine if your algorithm will
    run in time. For example, if the maximum input size n is 100K (or 105 ; 1K = 1, 000), and
    your current algorithm has a time complexity of O(n<sup>2</sup>), common sense (or your calculator)
    will inform you that (100K)2 or 1010 is a very large number that indicates that your algo-
    rithm will require (on the order of) hundreds of seconds to run. You will thus need to devise
    a faster (and also correct) algorithm to solve the problem. Suppose you find one that runs
    with a time complexity of O(n log<sub>2</sub> n). Now, your calculator will inform you that 105 log<sub>2</sub> 105
    is just 1.7 × 106 and common sense dictates that the algorithm (which should now run in
    under a second) will likely be able to pass the time limit.

-   #### Familiarity with these bounds:

    -   2<sup>10</sup> = 1024 ≈ 10<sup>3</sup>, 2<sup>20</sup> = 1048576 ≈ 10<sup>6</sup> .
    -   32-bit signed integers (int) and 64-bit signed integers (long long) have upper
        limits of 2<sup>31 −1</sup> ≈ 2 ×109 (safe for up to ≈ 9 decimal digits) and 2<sup>63 −1</sup> ≈ 9 ×1018
        (safe for up to ≈ 18 decimal digits) respectively.
    -   Unsigned integers can be used if only non-negative numbers are required. 32-bit
        unsigned integers (unsigned int) and 64-bit unsigned integers (unsigned long
        long) have upper limits of 2<sup>32 − 1</sup> ≈ 4 × 109 and 2<sup>64 − 1</sup> ≈ 1.8 × 1019 respectively.
    -   If you need to store integers ≥ 2<sup>64</sup>, use the Big Integer technique.
    -   There are n! permutations and 2n subsets (or combinations) of n elements.
    -   The best time complexity of a comparison-based sorting algorithm is Ω(n log<sub>2</sub> n).
    -   Usually, O(n log<sub>2</sub> n) algorithms are sufficient to solve most contest problems.
    -   The largest input size for typical programming contest problems must be < 1M.
    -   A typical year 2013 CPU can process 100M = 10<sup>8</sup> operations in a few seconds.

-   If our array needs only to contain Boolean values (1/true and 0/false), we can use
    an alternative data structure other than an array—a C++ STL bitset. The bitset
    supports useful operations like reset(), set(), the [] operator and test().

-   The difference between these two data structures is simple:
    the C++ STL map (and Java TreeMap) stores (key → data) pairs whereas the C++ STL set (and Java TreeSet) only stores the key. For most (contest) problems, we use
    a map (to really map information) instead of a set (a set is only useful for efficiently
    determining the existence of a certain key).

-   The heap is another way to organize data in a tree. The (Binary) Heap is also a binary
    tree like the BST, except that it must be a complete 14 tree. Complete binary trees
    can be stored efficiently in a compact 1-indexed array of size n + 1, which is often
    preferred to an explicit tree representation. For example, the array A = {N/A, 90, 19,
    36, 17, 3, 25, 1, 2, 7} is the compact array representation of Figure 2.3 with index 0
    ignored. One can navigate from a certain index (vertex) i to its parent, left child, and
    right child by using simple index manipulation: i/2, 2 × i, and 2 × i + 1, respectively.
    These index manipulations can be made faster using bit manipulation techniques (see
    Section 2.2): i >> 1, i << 1, and (i << 1) + 1, respectively.

-   There is no notion of a ‘search’ in the Heap (unlike
    BSTs). The Heap instead allows for the fast extraction (deletion) of the maximum
    element: ExtractMax() and insertion of new items: Insert(v)—both of which can
    be easily achieved by in a O(log n)

-   The implementation of priority queue is available in the C++ STL queue library (or Java
    PriorityQueue). Priority Queues are an important component in algorithms like
    Prim’s (and Kruskal’s) algorithms for the Minimum Spanning Tree (MST) problem
    (see Section 4.3), Dijkstra’s algorithm for the Single-Source Shortest Paths (SSSP)
    problem (see Section 4.4.3), and the A\* Search algorithm

-   Four problem solving paradigms commonly used to attack prob-
    lems in programming contests, namely Complete Search (a.k.a Brute Force), Divide and
    Conquer, the Greedy approach, and Dynamic Programming.

### Abbreviations

A* : A Star<br>
ACM : Assoc of Computing Machinery<br>
AC : Accepted<br>
APSP : All-Pairs Shortest Paths<br>
AVL : Adelson-Velskii Landis (BST)<br>
BNF : Backus Naur Form<br>
BFS : Breadth First Search<br>
BI : Big Integer<br>
BIT : Binary Indexed Tree<br>
BST : Binary Search Tree<br>
CC : Coin Change<br>
CCW : Counter ClockWise<br>
CF : Cumulative Frequency<br>
CH : Convex Hull<br>
CS : Computer Science<br>
CW : ClockWise<br>
DAG : Directed Acyclic Graph<br>
DAT : Direct Addressing Table<br>
D&C : Divide and Conquer<br>
DFS : Depth First Search<br>
DLS : Depth Limited Search<br>
DP : Dynamic Programming<br>
DS : Data Structure<br>
ED : Edit Distance<br>
FIFO : First In First Out<br>
FT : Fenwick Tree<br>
GCD : Greatest Common Divisor<br>
ICPC : Intl Collegiate Prog Contest<br>
IDS : Iterative Deepening Search<br>
IDA* : Iterative Deepening A Star<br>
IOI : Intl Olympiad in Informatics<br>
IPSC : Internet Problem Solving Contest<br>
LA : Live Archive<br>
LCA : Lowest Common Ancestor<br>
LCM : Least Common Multiple<br>
LCP : Longest Common Prefix<br>
LCS1 : Longest Common Subsequence<br>
LCS2 : Longest Common Substring<br>
LIFO : Last In First Out<br>
LIS : Longest Increasing Subsequence<br>
LRS : Longest Repeated Substring<br>
LSB : Least Significant Bit<br>
MCBM : Max Cardinality Bip Matching<br>
MCM : Matrix Chain Multiplication<br>
MCMF : Min-Cost Max-Flow<br>
MIS : Maximum Independent Set<br>
MLE : Memory Limit Exceeded<br>
MPC : Minimum Path Cover<br>
MSB : Most Significant Bit<br>
MSSP : Multi-Sources Shortest Paths<br>
MST : Minimum Spanning Tree<br>
MWIS : Max Weighted Independent Set<br>
MVC : Minimum Vertex Cover<br>
OJ : Online Judge<br>
PE : Presentation Error<br>
RB : Red-Black (BST)<br>
RMQ : Range Min (or Max) Query<br>
RSQ : Range Sum Query<br>
RTE : Run Time Error<br>
SSSP : Single-Source Shortest Paths<br>
SA : Suffix Array<br>
SPOJ : Sphere Online Judge<br>
ST : Suffix Tree<br>
STL : Standard Template Library<br>
TLE : Time Limit Exceeded<br>
USACO : USA Computing Olympiad<br>
UVa : University of Valladolid<br>
WA : Wrong Answer<br>
WF : World Finals<br>
