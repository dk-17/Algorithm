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


# Time Complexity
* O(for each vertex using min heap: for each edge linearly: push vertices to min heap that edge points to)
* V = number of vertices
* O(V * (pop vertex from min heap + find unvisited vertices in edges * push them to min heap)).
* E = number of edges on each vertex
* O(V * (pop vertex from min heap + E * push unvisited vertices to min heap)). Note, that we can push the same node multiple times here before we get to "visit" it.
* O(V * (log(heap size) + E * log(heap size)))
* O(V * ((E + 1) * log(heap size)))
* O(V * (E * log(heap size)))
* E = V because each vertex can reference all other vertices
* O(V * (V * log(heap size)))
* O(V^2 * log(heap size))
* heap size is V^2 because we push to it every time we want to update a distance and can have up to V comparisons for each vertex. E.g. for the last vertex, 1st  
     vertex has distance 10, 2nd has 9, 3rd has 8, etc, so, we push each time to update
* O(V^2 * log(V^2))
* O(V^2 * 2 * log(V))
* O(V^2 * log(V))
* V^2 is also a total number of edges, so if we let E = V^2 (as in the official naming), we will get the O(E * log(V))
* if you have vertices A,B,C then A can connect to B and C. And B can connect to A and C. And C can connect to A and B. So any vertex can connect to V - 1 total
 vertices (except itself), so there can be V - 1 edges on each vertex, which is basically equal to V. So, E = V 
