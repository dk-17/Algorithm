// Divya Kambaria
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mod 1000000007
using namespace std;

vector<int> min_distance;
vector<int> parent;
vector<vector<int>> path;

void getPath(int source, int vertex,int index){
	if(parent[vertex] == -1){
		path[index].push_back(source);
		return;
	}

	getPath(source,parent[vertex],index);
	path[index].push_back(vertex);
}

void PrintSolution(int source,int nodes){

	for(int i = 1; i < nodes; i++){
		getPath(source, i, i);
	}
}



void ShortestPath(vector<vector<int>> & connections,int nodes){
	vector<vector<pair<int,int>>> adj_list(nodes);
	for(int i = 0; i < (int)connections.size(); i++){
		int x = connections[i][0];
		int y = connections[i][1];
		int w = connections[i][2];

		adj_list[x].push_back({w,y});
		adj_list[y].push_back({w,x});
	}
    //min heap;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
	min_distance[0] = 0;
	pq.push({0,0});

	while(!pq.empty()){
		auto temp = pq.top();
		pq.pop();
		int node = temp.second;
		int weight = temp.first;

		for(int i = 0; i < (int)adj_list[node].size(); i++){
             int x = adj_list[node][i].second;
             int w = adj_list[node][i].first;
             if(min_distance[x] > weight + w){
             	parent[x] = node;
             	min_distance[x] = weight + w;
             	pq.push({min_distance[x],x});
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

	int nodes;cin >> nodes;
	int edges; cin >> edges;
	min_distance.resize(nodes, INT_MAX);
	parent.resize(nodes,-1);
	path.resize(nodes);
	vector<vector<int>> connections(edges,vector<int>(3,0));
	for(int i = 0; i < edges; i++){
		for(int j = 0; j < 3; j++){
			cin >> connections[i][j];
		}
	}

   ShortestPath(connections,nodes);

   
   PrintSolution(0,nodes);

   for(int i = 0; i < (int)path.size(); i++){
   	cout<<"source to node "<<i<<"  min_ditacnce  "<<min_distance[i]<<"  path is --->";
    	for(int j = 0 ; j <(int)path[i].size(); j++){
   		    cout<<path[i][j]<<" ";
     	}
   	cout<<endl;
   }

}

// input
// 9
// 14
// 0 1 4
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
// source to node 0  min_ditacnce  0  path is --->
// source to node 1  min_ditacnce  4  path is --->0 1 
// source to node 2  min_ditacnce  12  path is --->0 1 2 
// source to node 3  min_ditacnce  19  path is --->0 1 2 3 
// source to node 4  min_ditacnce  21  path is --->0 7 6 5 4 
// source to node 5  min_ditacnce  11  path is --->0 7 6 5 
// source to node 6  min_ditacnce  9  path is --->0 7 6 
// source to node 7  min_ditacnce  8  path is --->0 7 
// source to node 8  min_ditacnce  14  path is --->0 1 2 8 
