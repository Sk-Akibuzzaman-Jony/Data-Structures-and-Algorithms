#include <bits/stdc++.h>
using namespace std;

class Heap{
  public:
  vector<int> arr; 

  Heap(){
    arr.push_back(-1);
  }

  void insert(int val){
    arr.push_back(val);
    int currIdx = arr.size()-1;
    while(currIdx > 1){
      int parentIdex = currIdx/2;
      if(arr[parentIdex] < arr[currIdx]){
        swap(arr[parentIdex], arr[currIdx]);
        currIdx = parentIdex;
      } else {
        break;
      }
    }
  }

  int deleteValue() {
    int ans = arr[1];
    arr[1] = arr[arr.size()-1];
    arr.pop_back();

    int index = 1;
    int size = arr.size()-1;
    while(index < size){
      int leftIdx = 2*index;
      int rightIdx = 2*index+1;

      int largest = index;

      if(leftIdx < size && arr[leftIdx] > arr[index]){
        largest = leftIdx;
      }
      if(rightIdx < size && arr[rightIdx] > arr[leftIdx]){
        largest = rightIdx;
      }
      if(largest == index){
        //already in correct pos
        break;
      } else {
        swap(arr[index], arr[largest]);
        index = largest;
      }
    }
    return ans;
  }
};


int main() {
  Heap h;
  h.arr.push_back(100);
  h.arr.push_back(50);
  h.arr.push_back(60);
  h.arr.push_back(40);
  h.arr.push_back(45);

  cout << "printing the heap - > " << endl;
  for(int x : h.arr){
    cout << x << " ";
  }
  cout << endl;

  h.insert(110);

  cout << "printing the heap after inserting - > " << endl;
  for(int x : h.arr){
    cout << x << " ";
  }
  cout << endl;

  h.deleteValue();

  cout << "printing the heap after deleteing  - > " << endl;
  for(int x : h.arr){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
