// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Kosaraju's Algo

class Solution
{
	public:
	void getTopoSort(int src, vector<vector<int>>& adj, stack<int>& s, vector<bool>& visited){
    	visited[src] = true;
    	for(int nbr : adj[src]){
    		if(!visited[nbr]){
    			getTopoSort(nbr, adj, s, visited);
    		}
    	}
    	s.push(src);
    }
    void dfs(int src, vector<vector<int>>& adjRev, vector<bool>& visited){
        visited[src] = true;
        for(int nbr : adjRev[src]){
            if(!visited[nbr]){
    			dfs(nbr, adjRev, visited);
    		}
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj){
    
    	//step 1 -> get topo sort
    	stack<int> s;
    	vector<bool> visited(V, false);
    
    	for(int i = 0; i < V; i++){
    		if(!visited[i])
    			getTopoSort(i, adj, s, visited);
    	}
    
    	//step 2 -> reverse all edges
    	vector<vector<int>> adjRev(V);
    	for(int i = 0; i < V; i++){
    		for(int x : adj[i]){
    		    adjRev[x].push_back(i);
    		}
    	}
    	
    	//step 3 -> traverse and count components using dfs
    	vector<bool> visited2(V, false);
    	int count = 0;
    	while(!s.empty()){
    	    int top = s.top(); s.pop();
    		if(!visited2[top]){
    		    count++;
    		    dfs(top, adjRev, visited2);
    		}
    			
    	}
    	
    	return count;
    	
    }
};
