// Divya Kambaria
// Dijkstra using priority_queue.
// The code calculate shortes distance form source to all nodes,
// But doesn't calculate path information.
// To calculate source toraget node-->break for loop when min distance node is equal to target node.
// Time complexity O(E log V) E->number of edges and V vertex/nodes;
// Applicable even in directed graph!
// cannot applicable in negative weight cycle,it may give correct answer for negative edges
// for negative weight cycle and edges "Bellman-Ford" can be used!

#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007
using namespace std;
set<int> s;
vector<int> ans;
vector<int> min_distance;
void ShortestPath(vector<vector<int>> & connections,int nodes){

   vector<vector<pair<int,int>>> adj_list(nodes);
    min_distance.resize(nodes,INT_MAX);
   for(int i = 0; i < (int)connections.size(); i++ )////---->O(E)
   {
   	int x = connections[i][0];
   	int y = connections[i][1];
   	int w = connections[i][2];

   	adj_list[x].push_back({w,y});
   	adj_list[y].push_back({w,x});
   }
 //priority_queue <int, vector<int>, greater<int> > pq;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
   pq.push({0,0});
   min_distance[0] = 0;
   
   while(!pq.empty()){//-------------->O(E)
     auto temp = pq.top();
     pq.pop();
     s.insert(temp.second);
     ans.push_back(temp.second);
     int node = temp.second;
     int weight= temp.first;

     for(int i = 0; i <(int) adj_list[node].size(); i++){
     	int n = adj_list[node][i].second;
     	int w = adj_list[node][i].first;

     	if(min_distance[n] > weight + w){
     		min_distance[n] = weight + w;
     		pq.push({min_distance[n],n});//---->insertion take O(log(E)) in pq
     	}
     }



   }

}



int main()
{
     #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
     #endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ll t; cin>>t;while(t--){ }
	int nodes; cin>> nodes;
	int edges ; cin >> edges;

	vector<vector<int>> connections(edges,vector<int>(3,0));
	for(int i = 0; i< edges; i++){
		for(int j = 0; j< 3; j++)
		cin>>connections[i][j];
	}
	

	ShortestPath(connections,nodes);
   
    cout<<endl;
    for(int i = 0; i <nodes; i++){
    	cout<<i<<" "<<min_distance[i]<<"";
    	cout<<endl;
    }
    cout<<"size of ans vecotor = "<<ans.size()<<endl;
    
   
}

// Input
// 9           //number of nodes
// 14         // number of edges
// 0 1 4      //node1, node2, weight
// 0 7 8
// 1 7 11
// 1 2 8
// 7 8 7
// 7 6 1
// 2 8 2
// 2 3 7
// 2 5 4
// 6 8 6
// 6 5 2
// 5 4 10
// 3 5 14
// 3 4 9

// Output
// node shortest distance from source node 0 
// 0          0
// 1          4
// 2          12
// 3          19
// 4          21
// 5          11
// 6          9
// 7          8
// 8          14

// size of ans vecotor = 11
