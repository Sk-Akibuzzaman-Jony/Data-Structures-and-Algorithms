class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int K) 
    { 
       int l = 0, r = N-1;
       int mid1, mid2;
       
       while(l <= r){
           int mid1 = l+(r-l)/2;
           int mid2 = r-(r-l)/2;
           
           if(K == arr[mid1]){
               return 1;
           }
           if(K == arr[mid2]){
               return 1;
           }
           
           if(K < arr[mid1]){
               r = mid1-1;
           }
           else if(K > arr[mid2]){
               l = mid2+1;
           } else {
               l = mid1+1;
               r = mid2-1;
           }
       }
       
       return -1;
    }
    
};
