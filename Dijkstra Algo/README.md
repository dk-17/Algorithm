* Dijkstra using priority_queue.
* The code calculate shortest distance form source to all nodes,
   But doesn't calculate path information.
* To calculate source toraget node-->break for loop when min distance node is equal to target node.
* Time complexity O(E log V) E->number of edges and V vertex/nodes;
* Applicable even in directed graph!
* cannot applicable in negative weight cycle,it may give correct answer for negative edges
*for negative weight cycle and edges "Bellman-Ford" can be used!