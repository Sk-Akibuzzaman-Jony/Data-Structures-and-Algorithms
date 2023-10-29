// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
        
        vector<long long> ans;
        
        queue<long long int> q;
        
        //process first k elements
        for(long long i = 0; i < k; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        
        for(long long i = k; i < n; i++){
            //push the neg number index to ans
            if(!q.empty()){
                ans.push_back(arr[q.front()]);
             } else {
                 ans.push_back(0);
             }
             
             //remove the elements those the lying out of the window
             if(!q.empty() && (i-q.front() >= k)){
                 q.pop();
             }
             
             //insert the new elements
             if(arr[i] < 0){
                 q.push(i);
             }
        }
        
        //push the ans for the last window
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        } else {
            ans.push_back(0);
        }
        
        return ans;
                                                 
                                                 
 }
