// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:
    void solve(Node* root, int& maxSum, int sum, int path, int& maxPath){
        if(root == NULL){
            return;
        }
        
        if (root->left == NULL && root->right == NULL){
            if(path >= maxPath){
                maxSum = sum+root->data;
                maxPath = path;
            }
            return;
        }
        sum = sum + root->data;
        
        solve(root->left, maxSum, sum, path+1, maxPath);
        solve(root->right, maxSum, sum, path+1, maxPath);
        
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxSum = INT_MIN;
        int maxPath = INT_MIN;
        solve(root, maxSum, 0, 0, maxPath);
        return maxSum;
    }
};
