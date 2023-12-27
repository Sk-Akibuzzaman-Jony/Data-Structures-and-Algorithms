// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
    bool hasCycle(int V, vector<int> adj[], unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited){
        visited[V] = true;
        dfsVisited[V] = true;
        for(auto x : adj[V]){
            if(!visited[x]){
                int ans = hasCycle(x, adj, visited, dfsVisited);
                if(ans) return true;
            } else if(dfsVisited[x]){
                return true;
            }
        }
        dfsVisited[V] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = hasCycle(i, adj, visited, dfsVisited);
                if(ans){
                    return ans;
                }
            }
        }
        return false;
    }
};
