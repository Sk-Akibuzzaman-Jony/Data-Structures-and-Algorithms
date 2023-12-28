// https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    void dfs(int V, vector<int> adj[], stack<int>& s, unordered_map<int, bool>& visited){
        visited[V] = true;
        for(auto x : adj[V]){
            if(!visited[x]){
                dfs(x, adj, s, visited);
            }
        }
        s.push(V);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    unordered_map<int, bool> visited;
	    stack<int> s;
	    for(int i = 0; i < V; i++){
	       if(!visited[i]){
	           dfs(i, adj, s, visited);
	       }
	    }
	    
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};
