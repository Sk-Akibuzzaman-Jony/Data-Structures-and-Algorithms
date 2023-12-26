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

  void bfs(int src){
    queue<int> q;
    unordered_map<int, bool> visited;
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
};

int main() {
  //undirected graph
  Graph g1;
  g1.addEdge(0, 1, false);
  g1.addEdge(1, 2, false);
  g1.addEdge(1, 3, false);
  g1.addEdge(3, 5, false);
  g1.addEdge(3, 7, false);
  g1.addEdge(7, 6, false);
  g1.addEdge(7, 4, false);
  g1.printAdjList();
  g1.bfs(0);

  return 0;
}

//output
// 4-->7 
// 6-->7 
// 7-->3 6 4 
// 5-->3 
// 3-->1 5 7 
// 2-->1 
// 1-->0 2 3 
// 0-->1 
// 0 1 2 3 5 7 6 4 
