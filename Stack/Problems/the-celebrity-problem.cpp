// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // make a stack and push all the persons in it 
        stack<int> stk;
        for(int i = 0; i < n; i++){
            stk.push(i);
        }
        
        // now pop the top two elements, say A and B, and check if they know rach other
        // if A knows B then push B as B could be a celebrity
        // if B knows A then push A as A could be a celebrity
        
        while(stk.size() > 1){
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            
            if(M[a][b] == 1){
                stk.push(b);
            } 
            else{
                stk.push(a);
            }
        }
        
        // the single element in stk is a potential celebrity
        // if the person does not know anybody and everybody knows him
        int potentialCelebrity = stk.top(); stk.pop();
        for(int i = 0; i < n; i++){
            if(M[potentialCelebrity][i] == 1){
                return -1;
            }
            if(M[i][potentialCelebrity] == 0 && i != potentialCelebrity){
                return -1;
            }
        }
        return potentialCelebrity;
    }
};
