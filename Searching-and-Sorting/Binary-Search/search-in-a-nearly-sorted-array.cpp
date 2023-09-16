/*
a nearly sorted array is an array where an element at index i in a correctly sorted order can be misplaced by the ± 1 position, i.e., it can be present at index i-1 or i or i+1.
*/

#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> arr, int target){
  int s = 0, e = arr.size()-1; 
  int mid;

  while(s<=e){
    mid = s+(e-s)/2;

    if(arr[mid] == target){
      return mid;
    }
    if(arr[mid-1] >=0 && arr[mid-1] == target){
      return mid-1;
    }
    if(arr[mid+1] < arr.size() && arr[mid+1] == target){
      return mid+1;
    }

    if(target < arr[mid]){
      e = mid-1;
    }
    else {
      s = mid+1;
    }

  }

  return -1;
}


int main() {
  
  vector<int> arr{10, 3, 40, 20, 50, 80, 70};
  int target = 40;

  int ans = binarySearch(arr, target);

  cout << target << " is present at index " << ans << endl;

  return 0;
}
