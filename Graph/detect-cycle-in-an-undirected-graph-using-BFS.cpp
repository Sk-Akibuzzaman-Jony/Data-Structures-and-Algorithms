// cycle detection in an undirected graph
// applicable for both connected and disconned
// using BFS

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

class Solution {
    bool hasCycle(int V, vector<int> adj[], unordered_map<int, int>&parent, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(V);
        parent[V] = -1;
        visited[V] = true;
        while(!q.empty()){
            int firstNode = q.front();q.pop();
            for(auto x : adj[firstNode]){
                if(!visited[x]){
                    q.push(x);
                    visited[x] = true;
                    parent[x] = firstNode;
                }
                else if(x != parent[firstNode]){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (hasCycle(i, adj, parent, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
    
};
