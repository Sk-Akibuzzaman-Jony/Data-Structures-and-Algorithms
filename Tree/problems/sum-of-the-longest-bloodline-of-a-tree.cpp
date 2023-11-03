// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:

    void solve(Node* root, int sum , int& maxSum, int &maxLen,int len){
        if(root == NULL){
            if(len > maxLen){
                maxSum = sum;
                maxLen = len;
            } else if(len == maxLen){
                maxSum = max(maxSum, sum);
            }
            return;
        }
        
        //move left 
        sum = sum + root->data;
        solve(root->left, sum, maxSum, maxLen, len+1);
        
        //move right
        solve(root->right, sum, maxSum, maxLen, len+1);
  
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        int maxLen = 0;
        solve(root, sum, maxSum, maxLen, 0);
        return maxSum;
    }
};
