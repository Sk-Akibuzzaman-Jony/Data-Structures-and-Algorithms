// https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> q1;
        queue<int> q2;
        
        int n = q.size();
        
        while(q.size() != n/2){
            q1.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            q2.push(q.front());
            q.pop();
        }
        
        vector<int> ans;
        while(ans.size() < n){
            ans.push_back(q1.front());
            q1.pop();
            ans.push_back(q2.front());
            q2.pop();
        }
        
        return ans;
    }
};
