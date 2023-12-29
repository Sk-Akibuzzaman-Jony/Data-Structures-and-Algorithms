// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution {
  public:
    void getTopoSort(int v, vector<vector<vector<int>>>& adj, stack<int>& topo, vector<int>& visited){
        visited[v] = true;
        for(auto x : adj[v]){
            if(!visited[x[0]]){
                getTopoSort(x[0], adj, topo, visited);
            }
        }
        topo.push(v);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //making adjacency list
        vector<vector<vector<int>>> adj(N);
        for(auto x : edges){
            adj[x[0]].push_back({x[1], x[2]});
        }
        vector<int> visited(N, false);
        stack<int> topo;
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                getTopoSort(i, adj, topo, visited);
            }
        }
        
        //updating distances for the nodes linked to src
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        for(auto nbr : adj[0]){
            if(dist[0] + nbr[1] < nbr[0]){
                dist[nbr[0]] = dist[0] + nbr[1];
            }
        }
        
        while(!topo.empty()){
            int topElem = topo.top();
            topo.pop();
            
            if(dist[topElem] != INT_MAX){
                for(auto nbr : adj[topElem]){
                    if(dist[topElem] + nbr[1] < dist[nbr[0]]){
                        dist[nbr[0]] = dist[topElem] + nbr[1];
                    }
                }
            }
        }
        
        for(auto& x : dist){
            if(x == INT_MAX){
                x = -1;
            }
        }
        
        return dist;
        
    }
};
