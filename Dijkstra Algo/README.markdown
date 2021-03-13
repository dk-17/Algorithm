* Dijkstra using priority_queue.
* The code calculate shortest distance form source to all nodes,
   But doesn't calculate path information.
* We can create a parent array, update the parent array when distance is updated (like prim’s implementation) and use it show the shortest path from source to       
  different vertices.
* To calculate source to traget node-->break for loop when min distance node is equal to target node.
* Time complexity O(E log V) E->number of edges and V vertex/nodes;
* Applicable even in directed graph!
* Cannot applicable in negative weight cycle,it may give correct answer for negative edges
* For negative weight cycle and edges "Bellman-Ford" can be used!


