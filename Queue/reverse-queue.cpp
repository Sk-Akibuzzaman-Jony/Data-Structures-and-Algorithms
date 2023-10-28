// https://practice.geeksforgeeks.org/problems/queue-reversal/1

//Function to reverse the queue.
class Solution
{
    public:
    
    void solveRec(queue<int>& q){
        //base case
        if(q.empty()){
            return;
        }
        
        int top = q.front();
        q.pop();
        
        solveRec(q);
        
        q.push(top);
    }
    
    queue<int> rev(queue<int> q)
    {
        solveRec(q);
        return q;
    }
};
