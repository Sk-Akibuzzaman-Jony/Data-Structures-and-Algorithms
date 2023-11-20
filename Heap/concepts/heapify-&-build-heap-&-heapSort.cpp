#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
  int index = i;
  int leftIndex = 2*index;
  int rightIndex = 2*index+i;
  int largest = index;  
  
  if(leftIndex <= n && arr[index] < arr[leftIndex]){
    largest = leftIndex;
  }
  if(rightIndex <= n && arr[leftIndex] < arr[rightIndex]){
    largest = rightIndex;
  }

  if(largest != index){
    swap(arr[index], arr[largest]);
    index = largest;
    heapify(arr, n, index);
  }
}

void buildHeap(int arr[], int n){
  for(int i = n/2; i > 0; i--){
    heapify(arr, n, i);
  }
}

void heapSort(int arr[], int n){
  while(n > 1){
    swap(arr[1], arr[n--]);
    heapify(arr, n, 1);
  }
}

int main() {
  int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
  int n = 11;
  buildHeap(arr, n);

  cout << "printing the heap "<< endl;
  for(int i=0; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);

  cout << "printing the heap after heapSort -> "<< endl;
  for(int i=0; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
