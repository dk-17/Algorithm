* Dijkstra using priority_queue.
* The code calculate shortest distance form source to all nodes,
   But doesn't calculate path information.
* To calculate source to traget node-->break for loop when min distance node is equal to target node.
* Time complexity O(E log V) E->number of edges and V vertex/nodes;
* Applicable even in directed graph!
* Cannot applicable in negative weight cycle,it may give correct answer for negative edges
* For negative weight cycle and edges "Bellman-Ford" can be used!

Input
9           //number of nodes
14         // number of edges
0 1 4      //node1, node2, weight
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
2 3 7
2 5 4
6 8 6
6 5 2
5 4 10
3 5 14
3 4 9

Output
node shortest distance from source node 0 
0          0
1          4
2          12
3          19
4          21
5          11
6          9
7          8
8          14

size of ans vecotor = 11
