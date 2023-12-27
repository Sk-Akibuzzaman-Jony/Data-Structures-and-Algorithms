// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0

// applicable for both connected and disconnected graph


class Solution {
    bool hasCycle(int V, vector<int> adj[], int parent, unordered_map<int, bool>& visited) {
        visited[V] = true;
        for(auto x : adj[V]){
            if(!visited[x]){
                bool aageKaAns = hasCycle(x, adj, V, visited);
                if(aageKaAns) return true;
            } else if(x != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (hasCycle(i, adj, -1, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
    
};
