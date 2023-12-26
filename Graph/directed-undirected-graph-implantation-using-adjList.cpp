// directed and undirected graph implementation using adjacency list

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
};

int main() {
  //undirected graph
  Graph g1;
  g1.addEdge(0, 1, false);
  g1.addEdge(1, 2, false);
  g1.addEdge(0, 2, false);
  g1.printAdjList();

  cout << endl;

  //directed graph
  Graph g2;
  g2.addEdge(0, 1, true);
  g2.addEdge(1, 2, true);
  g2.addEdge(0, 2, true);
  g2.printAdjList();
  return 0;
}

//output
// 2-->1 0 
// 1-->0 2 
// 0-->1 2 

// 1-->2 
// 0-->1 2 
