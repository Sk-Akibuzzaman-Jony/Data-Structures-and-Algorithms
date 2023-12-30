// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

//Dijkstra Algorithm

class Solution {
  public:
    // Dijkstra Algorithm
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //making an adj list 
        vector<vector<vector<int>>> adj(N);
        for(auto x : edges){
            adj[x[0]].push_back({x[1], x[2]});
        }
        
        //making a distance array
        vector<int> dist(N, INT_MAX);
        
        //making a set of pair<distance, node>
        set<pair<int, int>> s;
        
        dist[0] = 0;
        s.insert({0, 0}); 
        
        while(!s.empty()){
            //fetch the smallest or the first element of the set
            auto firstNode = *s.begin();
            s.erase(firstNode);
            int node = firstNode.second;
            int nodeDistance = firstNode.first;
            
            for(auto nbr : adj[node]){
                if(nodeDistance + nbr[1] < dist[nbr[0]]){
                    //update distance
                    auto res = s.find({nbr[1], nbr[0]});
                    if(res != s.end()){
                        s.erase(res);
                    }
                    dist[nbr[0]] = nodeDistance + nbr[1];
                    s.insert({dist[nbr[0]], nbr[0]});
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
