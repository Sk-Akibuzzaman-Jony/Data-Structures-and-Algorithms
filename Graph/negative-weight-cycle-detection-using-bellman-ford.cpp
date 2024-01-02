// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    //edge cases
	    if(edges.size() == 0) return 0;
	    
	    //making adjacency list
	    vector<vector<vector<int>>> adj(n);
	    for(auto x : edges){
	        adj[x[0]].push_back({x[1], x[2]});
	    }
	    
	    //using bellman ford algorithm
	    vector<int> dist(n, INT_MAX);
	    
	    // we can take src as 0 but for some test cases 
	    // we cannot move anywhere from 0 so we have to take any other src
	    // from where we can atleast move
	    int src = edges[0][0];
	    dist[src] = 0;
	    
	    // relaxing for n-1 times
	    for(int i = 0; i < n-1; i++){
	        for(int node = 0; node < n; node++){
	             for(auto nbr : adj[node]){
	                 int u = node;
	                 int v = nbr[0];
	                 int w = nbr[1];
	                 if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
	                     dist[v] = dist[u]+w;
	                 }
	             }
	        }
	    }
	    
	    //now here dist contains the the shortest paths from src if there is 
	    //no negetive cycle
	    
	    //now we run the relaxation for one more time and if the distances gets updated
	    //a negetive cycle is present
	    bool isNegetiveCycle = false;
	    for(int node = 0; node < n; node++){
             for(auto nbr : adj[node]){
                 int u = node;
                 int v = nbr[0];
                 int w = nbr[1];
                 if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
                     isNegetiveCycle = true; //cycle found
                     return 1;
                 }
             }
        }
        return 0;	   
	}
};
