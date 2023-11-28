// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

class Solution{
    public:
    void heapify(vector<int>& c, int i, int n){
        while(true){
            int leftIndex = 2*i+1;
            int rightIndex = 2*i+2;
            int largest = i;
            if(leftIndex < n && c[leftIndex] > c[i]){
                largest = leftIndex;
            }
            if(rightIndex < n && c[largest] < c[rightIndex]){
                largest = rightIndex;
            }
            if(largest == i) break;
            swap(c[i], c[largest]);
            i = largest;
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //concat the two vectors
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());
        
        //heapify the elements
        int size = n+m;
        for(int i = (size/2)-1; i >= 0; i--){
            heapify(c, i, size);
        }
        return c;
    }
