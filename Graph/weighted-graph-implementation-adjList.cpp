// weighted graph implementation using adjacency list 
#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
  unordered_map<int, list<pair<int, int>>> adjList;

  void addEdge(int u, int v, int weight, bool directed){
    adjList[u].push_back({v, weight});
    if(directed == 0){
      adjList[v].push_back({u, weight});
    }
  }

  void printAdjList(){
    for(auto& x : adjList){
      cout << x.first << "-->";
      for(auto& y : x.second){
        cout << "{" << y.first << "," << y.second << "}" << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  Graph g;
  g.addEdge(0, 1, 5, 1);
  g.addEdge(1, 2, 8, 1);
  g.addEdge(0, 2, 6, 1);
  g.printAdjList();
  return 0;
}

//output
// 1-->{2,8} 
// 0-->{1,5} {2,6} 
