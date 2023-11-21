// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
       // creating as max-heap
       priority_queue<int> q;
       
       //inserting k elements
        for(int i = l; i < k; i++){
            q.push(arr[i]);
        }
        
        //now insering the remaining values iff they are smaller than
        //the top of the heap, during insertion also pop the top
        for(int i = k; i <= r; i++){
            if(arr[i] < q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        // q.top is the ans
        return q.top();
    }
};
