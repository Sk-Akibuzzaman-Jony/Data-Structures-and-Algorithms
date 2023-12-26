#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
  unordered_map<int, list<int>> adjList;

  void addEdge(int u, int v, bool directed){
    adjList[u].push_back(v);
    if(directed == 0){
      adjList[v].push_back(u);
    }
  }

  void printAdjList(){
    for(auto& x : adjList){
      cout << x.first << "-->";
      for(auto& y : x.second){
        cout << y << " ";
      }
      cout << endl;
    }
  }

  void bfs(int src, unordered_map<int, bool>& visited){
    queue<int> q;
    
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
      int frontNode = q.front(); q.pop();
      cout << frontNode << " ";
      //inserting neighbours
      for(auto neighbour : adjList[frontNode]){
        if(!visited[neighbour]){
          q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
    cout << endl;
  }
  
  void dfs(int src, unordered_map<int, bool>& visited){
      cout << src << " ";
      visited[src] = true;
      
      for(auto neighbour : adjList[src]){
          if(!visited[neighbour])
            dfs(neighbour, visited);
      }
  }
};

int main() {
  //undirected graph
  Graph g1;
  g1.addEdge(0, 1, false);
  g1.addEdge(1, 2, false);
  //g1.addEdge(1, 3, false);
  g1.addEdge(3, 5, false);
  g1.addEdge(3, 7, false);
  g1.addEdge(7, 6, false);
  g1.addEdge(7, 4, false);
  
  //for disconnected graph loop over all the nodes in graph
  //and call bfs
  unordered_map<int, bool> visited;
  for(int i = 0; i <= 7; i++){
      if(!visited[i]){
          g1.bfs(i, visited);
      }
  }
  cout << endl;
  cout << "DFS --> " << endl;
  unordered_map<int, bool> visited2;
  for(int i = 0; i <= 7; i++){
      if(!visited2[i]){
          g1.bfs(i, visited2);
      }
  }

  return 0;
}
