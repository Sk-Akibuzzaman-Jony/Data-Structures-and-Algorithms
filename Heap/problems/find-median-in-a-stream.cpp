#include <bits/stdc++.h>
using namespace std;


void solve(double& median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int element){
  if(maxHeap.size() == minHeap.size()){
    if(element < median){
      maxHeap.push(element);
      median = maxHeap.top();
    } else {
      minHeap.push(element);
      median = minHeap.top();
    }
  }
  else if(maxHeap.size() < minHeap.size()){
    if(element < median){
      minHeap.push(element);
      median = (minHeap.top()+maxHeap.top())/2.0;
    } else {
      int top = minHeap.top(); minHeap.pop();
      maxHeap.push(top);
      minHeap.push(element);
      median = (minHeap.top()+maxHeap.top())/2.0;
    }
  } else {
    if(element > median){
      minHeap.push(element);
      median = (minHeap.top()+maxHeap.top())/2.0;
    } else {
      int top = maxHeap.top(); maxHeap.pop();
      minHeap.push(top);
      maxHeap.push(element);
      median = (minHeap.top()+maxHeap.top())/2.0;
  }
}
}

int main() {
  vector<int> arr = {5,15,1,3};
  int n = 4;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;  
  double median = 0;
  for(int i = 0; i < n; i++){
    solve(median, maxHeap, minHeap, arr[i]);
    cout << median << endl;
  }
  return 0;
}
