// https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int> q;
	    unordered_map<int, int> indegree;
	    
	    //calculating indegree
	    for(int i = 0; i < V; i++){
	        for(auto nbs : adj[i]){
	            indegree[nbs]++;
	        }
	    }
	    
	    //push the node with indegree 0 in the queue
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int firstNode = q.front(); q.pop();
	        ans.push_back(firstNode);
	        for(auto x : adj[firstNode]){
	            indegree[x]--;
	            if(indegree[x] == 0){
	                q.push(x);
	            }
	        }
	    }
	    
	    return ans;
	}
};
